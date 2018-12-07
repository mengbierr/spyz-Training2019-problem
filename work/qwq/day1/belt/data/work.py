#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
for i in os.listdir('.'):
	if os.path.isfile(i) and os.path.splitext(i)[1]=='.out':
		print(i)
		f=open(i,'r')
		c=os.path.splitext(i)[0]+'.ans'
		g=open(c,'w')
		g.write(f.read())
		f.close()
		g.close()
		os.remove(i)