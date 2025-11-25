#!/usr/bin/make -f

compile            :
	#---(zeno_lib)--------------------#
	gcc -std=gnu89 -c -g -pg -Wall -Wextra zeno_lib.c
	gcc -o zeno_lib zeno_lib.o
	#---(zeno_ver)--------------------#
	gcc -std=gnu89 -c -g -pg -Wall -Wextra zeno_ver.c
	gcc -o zeno_ver zeno_ver.o
	#---(done)------------------------#

install            :
	#---(headers)---------------------#
	cp -f zeno_opengl.h  /usr/local/include
	@sha1sum             /usr/local/include/zeno_opengl.h
	cp -f zeno_curses.h  /usr/local/include
	@sha1sum             /usr/local/include/zeno_curses.h
	#---(zeno_lib)--------------------#
	cp -f zeno_lib       /usr/local/sbin/zeno_lib
	@sha1sum             /usr/local/sbin/zeno_lib
	#---(zeno_ver)--------------------#
	cp -f zeno_ver       /usr/local/sbin/zeno_ver
	@sha1sum             /usr/local/sbin/zeno_ver
	#---(zeno_inst)-------------------#
	cp -f zeno_inst.sh   /usr/local/sbin/zeno_inst
	@sha1sum             /usr/local/sbin/zeno_inst
	#---(prep/make)-------------------#
	cp -f zeno_prep      /usr/local/sbin/zeno_prep
	@sha1sum             /usr/local/sbin/zeno_prep
	cp -f zeno_make      /usr/local/sbin/zeno_make
	@sha1sum             /usr/local/sbin/zeno_make
	#---(commit)----------------------#
	cp -f zeno_now.sh    /usr/local/sbin/zeno_now
	@sha1sum             /usr/local/sbin/zeno_now 
	#---(update security)-------------#
	chown root:root      /usr/local/sbin/zeno_*
	chmod 0755           /usr/local/sbin/zeno_*
	#---(specialty)-------------------#
	chmod +s             /usr/local/sbin/zeno_lib   
	chmod +s             /usr/local/sbin/zeno_ver
	#---(done)------------------------#

units              :
	cp  -f zeno_make.munit zeno_make.c
	gcc -c zeno_make.c      -o zeno_make.o
	gcc -o zeno_make_munit     zeno_make.o  -lyUNIT -lyVAR -lyLOG -lyURG
	rm  -f zeno_make.c

deepclean          :
	#---(executables)---------------------#
	rm -f       zeno_lib
	rm -f       zeno_ver
	#---(object and stripped files)-------#
	rm -f       *.o
	rm -f       *.cs
	rm -f       *.os
	#---(HTAG stuff)----------------------#
	rm -f       HTAG.c
	rm -f       HTAG.gcalls
	rm -f       HTAG.lcalls
	rm -f       HTAG.depth
	rm -f       HTAG.mydepth
	rm -f       polymnia.htags
	rm -f       polymnia.mystry
	rm -f       polymnia.ylib
	#---(junk files)----------------------#
	rm -f       2
	rm -f       , 
	rm -f       ,q
	rm -f       ,qq
	rm -f       :w
	rm -f       :{
	rm -f       *~
	rm -f       temp*
	rm -f       version.txt
	rm -f       gdb_head

vi_edit            :
	vi -c "call HBUF_on()" -c "call HTAG_on()" zeno.h zeno_lib.c zeno_ver.c zeno_inst.sh zeno_prep zeno_make zeno_now.sh zeno_opengl.h zeno_curses.h Makefile

vi_unit            :
	vi -c "call HBUF_on()" -c "call HTAG_on()" unit_head.munit zeno_make.munit

remove             :
	#---(new names and versions)----------#
	rm -f       /usr/local/include/zeno_opengl.h
	rm -f       /usr/local/include/zeno_curses.h
	rm -f       /usr/local/sbin/zeno_lib
	rm -f       /usr/local/sbin/zeno_ver
	rm -f       /usr/local/sbin/zeno_inst
	rm -f       /usr/local/sbin/zeno_prep
	rm -f       /usr/local/sbin/zeno_make
	rm -f       /usr/local/sbin/zeno_now
	#---(old names and versions)----------#
	rm -f       /usr/local/include/make_opengl.h
	rm -f       /usr/local/include/make_curses.h
	rm -f       /usr/local/sbin/_lib
	rm -f       /usr/local/sbin/getver
	rm -f       /usr/local/sbin/_inst
	rm -f       /usr/local/sbin/make_program
	rm -f       /usr/local/sbin/make_prepare
	rm -f       /usr/local/sbin/git_now 

