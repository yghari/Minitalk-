# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yghari <yghari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 20:23:28 by yghari            #+#    #+#              #
#    Updated: 2022/01/11 02:26:14 by yghari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
SERVER=server
CLIENT=client
CSRC=client.c
SSRC=server.c
COBJ=$(CSRC:.c=.o)
SOBJ=$(SSRC:.c=.o)

FLAGS=-Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

bonus: all

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
	
$(CLIENT): $(COBJ)
	$(CC) $(FLAGS) $(COBJ) -o $(CLIENT)
	
$(SERVER): $(SOBJ)
	$(CC) $(FLAGS) $(SOBJ) -o $(SERVER)
clean:
	rm -f *.o

fclean:	clean
	rm -rf $(CLIENT) $(SERVER)

re:	fclean all