CXX = g++
CXXFLAGS = -Wall -std=c++11

SRC = src 
DEST = tmp 
init: 	
	mkdir src 
	mkdir tmp 
aviv: 
	$(CXX) $(CXXFLAGS) CachingFileSystem.cpp log.cpp -o aviv -D_FILE_OFFSET_BITS=64 -lfuse 
umount: 
	fusermount -u $(DEST) 
mount: 
	aviv $(SRC) $(DEST) 12 1024 
force: 
	umount -l $(DEST) 
	
clean:
	$(RM) aviv *~ *core
.PHONY: 
	all clean tar mount umount force
