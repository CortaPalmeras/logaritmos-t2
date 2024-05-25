
out_dir := ./bin

source_dir := ./src
source_files := $(source_dir)/*

header_dir := ./include
header_files := $(header_dir)/*

test_dir := ./test
test_files := $(test_dir)/*

CPPFLAGS := -Iinclude -Wall -Wextra -Werror -pedantic

ifdef debug
	CPPFLAGS += -g
else ifdef san
	CPPFLAGS += -fsanitize=address
else
	CPPFLAGS += -O3
endif

temp:
	$(CC) src/* test/* $(CPPFLAGS) -o bin/prueba
	bin/prueba

$(out_dir):
	mkdir $(our_dir)

format:
	clang-format -i $(source_files) $(header_files) $(test_files)

clean:
	rm $(output_dir)/*

