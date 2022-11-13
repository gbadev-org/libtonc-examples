SUBDIRS:= `ls`

#---------------------------------------------------------------------------------
all: examples
#---------------------------------------------------------------------------------
	@rm -fr bin
	@mkdir -p bin
	@find . -path ./bin -prune -o -name "*.gba" -exec cp -fv {} bin \;

examples:
	@for i in $(SUBDIRS); do if test -e $$i/Makefile ; then $(MAKE) -C $$i || { exit 1;} fi; done;

#---------------------------------------------------------------------------------
clean:
#---------------------------------------------------------------------------------
	@rm -fr bin
	@for i in $(SUBDIRS); do if test -e $$i/Makefile ; then $(MAKE)  -C $$i clean || { exit 1;} fi; done;
