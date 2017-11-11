import threading

if __name__ == '__main__':
	lock = threading.Lock()
	lock.acquire()
	print("Hello World")
