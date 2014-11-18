import os
import sys

path = sys.argv[1]

with open(path + '\\SDK\\Include\\stl\\config\\stl_msvc.h') as file:
	fixed = file.read().endswith('#undef _STLP_NO_TYPENAME_ON_RETURN_TYPE\n')
if not fixed:
	with open(path + '\\SDK\\Include\\stl\\config\\stl_msvc.h', 'a') as file:
		file.write('#undef _STLP_NO_TYPENAME_ON_RETURN_TYPE\n')

with open(path + '\\SDK\\Include\\stl\\cstdio') as file:
	text = file.read()
with open(path + '\\SDK\\Include\\stl\\cstdio', 'w') as file:
	file.write(text.replace('_STLP_VENDOR_CSTD::_vsnprintf', '_vsnprintf').replace('_STLP_VENDOR_CSTD::vsnprintf', '::vsnprintf'))

for directory, directories, files in os.walk(path + '\\SDK\\Include\\stl'):
	for name in files:
		with open(directory + '\\' + name) as file:
			text = file.read()
		with open(directory + '\\' + name, 'w') as file:
			file.write(text.replace('__value', '__val'))
