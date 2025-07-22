SRCS=pedalboard.cc
OBJS=$(addprefix obj/,$(addsuffix .o,$(basename $(SRCS))))

# add -I includerfolder1 -I includefolder2...
CFLAGS+=-I include -I /usr/include/nlohmann

vpath %.cc src

obj/%.o:%.cc
	$(CXX) -c -o $@ $(CXXFLAGS) $(CFLAGS) $^

.PHONY: all
all: pedalboard jsontest

# change the program name before the colon
# add a -l libraryname -l libraryname2 below
pedalboard:$(OBJS)
	g++ -o $@ $(OBJS)

JSON_TEST_SRCS=jsontest.cc ip4_address.cc tcp4_socket.cc
JSON_TEST_OBJS=$(addprefix obj/,$(addsuffix .o,$(basename $(JSON_TEST_SRCS))))
jsontest: $(JSON_TEST_OBJS)
	g++ -o $@ $(JSON_TEST_OBJS)

#change the prgram name below
.PHONY: clean
clean:
	rm -f pedalboard jsontest obj/*
