import socket
import psutil
import time
import json
import wmi
import pynvml


def get_cpu_usage():
    return psutil.cpu_percent(interval=1)


def get_memory_usage():
    memory_info = psutil.virtual_memory()
    return memory_info.used / memory_info.total


def get_disk_usage():
    disk_info = psutil.disk_usage('C:\\')
    return disk_info.free / disk_info.total


def get_gpu_usage():
    pynvml.nvmlInit()
    handle = pynvml.nvmlDeviceGetHandleByIndex(0)
    utilization = pynvml.nvmlDeviceGetUtilizationRates(handle)
    pynvml.nvmlShutdown()
    return utilization.gpu


def main():
    # 连接ESP8266开发板的UDP服务器
    host = '192.168.1.42'  # ESP8266开发板的IP地址
    port = 8888
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    while True:
        cpu_usage = get_cpu_usage()
        memory_usage = get_memory_usage()
        disk_usage = get_disk_usage()
        gpu_usage = get_gpu_usage()

        # 将数据封装成JSON格式
        data = {
            'cpu': f"{round(cpu_usage, 1)}%",  # 保留一位小数
            'memory': f"{int(memory_usage * 100)}%",  # 转换为整数形式并加上百分号
            'disk': f"{int(disk_usage * 100)}%",  # 转换为整数形式并加上百分号
            'gpu': f"{int(gpu_usage)}%"  # 获取电脑 GPU 使用率
        }
        json_data = json.dumps(data)

        # 发送JSON数据到ESP8266开发板
        sock.sendto(json_data.encode(), (host, port))

        # 打印发送的JSON数据
        print(f"Sent data: {json_data}")

        # 等待一段时间再进行下一次数据采集和发送
        time.sleep(1)


if __name__ == '__main__':
    main()
