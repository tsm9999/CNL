import sys
import socket
import threading

sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
server_address=('127.0.0.1',50000)
global data
global address

def get_message():
    global address
    while True:
        data,address=(sock.recvfrom(1000))
        print('\n>From {}, message: {}'.format(address,data.decode(encoding='UTF-8')))
        sys.stdout.flush()
        sys.stdin.flush()

def send_message():
    while True:
        message=bytes(input(),'UTF-8')
        sock.sendto(message,server_address)
        sys.stdout.flush()
        sys.stdin.flush()

def main():
    sock.bind(('127.0.0.1',5000))
    thread1=threading.Thread(target=get_message,args=())
    thread2=threading.Thread(target=send_message,args=())
    thread1.start()
    thread2.start()

if __name__ =='__main__':
    main()