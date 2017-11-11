def read_one():
	fo = open("example.txt", "r")
	fo.write("something")

def read_two():
	fo = open("example.txt", "r")
	print(fo.read())
	fo.close()
	fo.close()

def read_three():
	fo = open("example.txt", "r")
	fo.close()
	print(fo.read())

def read_four():
	fo = open("example.txt", "r")
	print(fo.read())

if __name__ == '__main__':
	read_two()
	read_three()
	read_four()
	read_one()