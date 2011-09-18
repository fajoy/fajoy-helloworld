#!/usr/bin/python
import sys

class Hello:
	name="fajoy"
	def __init__(self,name):
		self.name=name

	def show(self,text):
		if text:
			print self.name +":" +text
		else:
			print self.name + ":Hello World!!"

if __name__ == "__main__":
	s=Hello("fajoy")
        if len(sys.argv)>1:
		s.show(sys.argv[1])
	else:
		s.show("")
