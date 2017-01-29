TARGET  = Assignment1
SRCS	= 	Util/cmdLineParser \
		Image/bmp \
		Image/image \
		Image/image.todo \
		Image/jpeg \
		Image/lineSegments \
		Image/lineSegments.todo \
		main

CC   = g++
CFLAGS		+= -I.
LFLAGS		+= -LJPEG -lJPEG

OBJECTS		= ${addsuffix .o, ${SRCS}}
CLEAN		= *.o .depend ${TARGET} *.dsp *.dsw *.bak

#############################################################
all: debug

debug: CFLAGS += -DUSE_UNIX -DDEBUG -g3
debug: ${TARGET}

release: CFLAGS += -O2 -DUSE_UNIX -DRELEASE -pipe -fomit-frame-pointer
release: ${TARGET}

${TARGET}: depend JPEG/libJPEG.a ${OBJECTS}
	${CC} -o $@ ${OBJECTS} ${LFLAGS}

clean:	
	/bin/rm -f ${CLEAN}

.cpp.o:
	${CC} ${CFLAGS} -o $@ -c $<

JPEG/libJPEG.a:
	${MAKE} -C JPEG

depend: 
	makedepend -- ${CFLAGS} -- ${addsuffix .cpp, ${SRCS}}
# DO NOT DELETE

Util/cmdLineParser.o: /usr/include/stdio.h /usr/include/features.h
Util/cmdLineParser.o: /usr/include/stdc-predef.h /usr/include/libio.h
Util/cmdLineParser.o: /usr/include/_G_config.h /usr/include/wchar.h
Util/cmdLineParser.o: /usr/include/stdlib.h /usr/include/alloca.h
Util/cmdLineParser.o: /usr/include/string.h /usr/include/assert.h
Util/cmdLineParser.o: Util/cmdLineParser.h
Image/bmp.o: Image/bmp.h Image/image.h /usr/include/stdio.h
Image/bmp.o: /usr/include/features.h /usr/include/stdc-predef.h
Image/bmp.o: /usr/include/libio.h /usr/include/_G_config.h
Image/bmp.o: /usr/include/wchar.h Image/lineSegments.h /usr/include/stdlib.h
Image/bmp.o: /usr/include/alloca.h
Image/image.o: /usr/include/string.h /usr/include/features.h
Image/image.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Image/image.o: /usr/include/alloca.h Image/image.h /usr/include/stdio.h
Image/image.o: /usr/include/libio.h /usr/include/_G_config.h
Image/image.o: /usr/include/wchar.h Image/lineSegments.h
Image/image.o: ./Util/cmdLineParser.h ./Image/bmp.h ./Image/jpeg.h
Image/image.todo.o: Image/image.h /usr/include/stdio.h
Image/image.todo.o: /usr/include/features.h /usr/include/stdc-predef.h
Image/image.todo.o: /usr/include/libio.h /usr/include/_G_config.h
Image/image.todo.o: /usr/include/wchar.h Image/lineSegments.h
Image/image.todo.o: /usr/include/stdlib.h /usr/include/alloca.h
Image/image.todo.o: /usr/include/math.h /usr/include/time.h
Image/jpeg.o: Image/jpeg.h Image/image.h /usr/include/stdio.h
Image/jpeg.o: /usr/include/features.h /usr/include/stdc-predef.h
Image/jpeg.o: /usr/include/libio.h /usr/include/_G_config.h
Image/jpeg.o: /usr/include/wchar.h Image/lineSegments.h /usr/include/assert.h
Image/jpeg.o: /usr/include/stdlib.h /usr/include/alloca.h ./JPEG/jpeglib.h
Image/jpeg.o: ./JPEG/jconfig.h ./JPEG/jmorecfg.h /usr/include/setjmp.h
Image/lineSegments.o: Image/lineSegments.h /usr/include/stdio.h
Image/lineSegments.o: /usr/include/features.h /usr/include/stdc-predef.h
Image/lineSegments.o: /usr/include/libio.h /usr/include/_G_config.h
Image/lineSegments.o: /usr/include/wchar.h /usr/include/math.h
Image/lineSegments.todo.o: Image/lineSegments.h /usr/include/stdio.h
Image/lineSegments.todo.o: /usr/include/features.h /usr/include/stdc-predef.h
Image/lineSegments.todo.o: /usr/include/libio.h /usr/include/_G_config.h
Image/lineSegments.todo.o: /usr/include/wchar.h /usr/include/math.h
main.o: /usr/include/stdio.h /usr/include/features.h
main.o: /usr/include/stdc-predef.h /usr/include/libio.h
main.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/stdlib.h
main.o: /usr/include/alloca.h ./Image/bmp.h Image/image.h
main.o: Image/lineSegments.h ./Image/jpeg.h Image/image.h
main.o: ./Util/cmdLineParser.h /usr/include/string.h
