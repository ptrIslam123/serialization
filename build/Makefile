CC="gcc"
RES="main"

STATCI_N="widget"
SHARED_N="Swidget"

LIB_SRC="serialization/math.c"
LIB_SRC_BIN="math.o"

LIB_PATH="/home/islam/Cprogarm/SystemLib/build"


main.o:
	$(CC) -Wall -g -c ../main.c


rm.main.o:
	rm -rf main.o


libsrc.o:
	$(CC) -Wall -g -c ../$(LIB_SRC)


libsrc.o.so:
	$(CC) -fPIC -Wall -g -c ../$(LIB_SRC)

	

ar.libsrc:
	ar rc lib$(STATCI_N).a $(LIB_SRC_BIN)
	ranlib lib$(STATCI_N).a


set_ld_library_path:
	LD_LIBRARY_PATH=$(LIB_PATH):${LD_LIBRARY_PATH}
	export LD_LIBRARY_PATH


shared.libsrc:
	make libsrc.o.so
	$(CC) -shared -o lib$(SHARED_N).so $(LIB_SRC_BIN)
	


static.libsrc:
	make libsrc.o
	make ar.libsrc


link.main.with.libsrc.a:
	$(CC) main.o -L$(LIB_PATH) -l$(STATCI_N) -o $(RES)	


link.main.with.libsrc.so:
	$(CC) main.o -L$(LIB_PATH) -l$(SHARED_N) -o $(RES)
	make set_ld_library_path


main.static:
	make main.o
	make static.libsrc
	make link.main.with.libsrc.a

main.shared:
	make shared.libsrc
	make main.o
	make link.main.with.libsrc.so



update.static.libsrc:
	make libsrc.o
	make static.libsrc
	make link.main.with.libsrc.a


update.shared.libsrc:
	make libsrc.o.so
	make shared.libsrc
	make link.main.with.libsrc.so

update.main.o:
	make rm.main.o
	make main.o


run:
	./$(RES)


debug.kdbg:
	kdbg ./$(RES)


debug.gdb:
	gdb ./$(RES)


clear:
	rm -rf *.o
	rm -rf $(RES)
	rm -rf lib$(STATCI_N).a
	rm -rf lib$(SHARED_N).so