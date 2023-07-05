CC = gcc

SRC_1 = process_info.c
SRC_2 = kill_it.c
SRC_3 = who_sig_me.c
SRC_4 = signal_me.c

SRC_OBJ_1 = process_info.o
SRC_OBJ_2 = kill_it.o
SRC_OBJ_3 = who_sig_me.o
SRC_OBJ_4 = signal_me.o

CFLAGS = -W -Wall -Wextra
CFLAGS += -L. -Iinclude/ -Llib -lmy

TARGET_1 = process_info
TARGET_2 = kill_it
TARGET_3 = who_sig_me
TARGET_4 = signal_me

SRC_OBJS = $(SRC_OBJ_1) $(SRC_OBJ_2) $(SRC_OBJ_3) $(SRC_OBJ_4)
TARGETS = $(TARGET_1) $(TARGET_2) $(TARGET_3) $(TARGET_4)

all: $(TARGETS)

$(TARGETS): $(SRC_OBJS)
	@ $(CC) -o $(TARGET_1) $(SRC_OBJ_1) $(CFLAGS)
	@ $(CC) -o $(TARGET_2) $(SRC_OBJ_2) $(CFLAGS)
	@ $(CC) -o $(TARGET_3) $(SRC_OBJ_3) $(CFLAGS)
	@ $(CC) -o $(TARGET_4) $(SRC_OBJ_4) $(CFLAGS)

clean:
	@ rm -f $(SRC_OBJS)
	@ echo "clean has been done succesfully"

fclean: clean
	@ rm -f $(TARGETS)
	@ echo "fclean has been done succesfully"