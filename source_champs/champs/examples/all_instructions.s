# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    all_instructions.s                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 11:58:42 by hmaronen          #+#    #+#              #
#    Updated: 2023/01/13 11:58:45 by hmaronen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name "All Instructions"
.comment "Yes, all of them"

live %1

ld 	%21, 	r1
ld	42,		r2

st	r2,		r1
st	r3,		21

add	r1,		r2,		r3

sub	r3,		r2,		r1

and	r1,		r2,		r3
and	%21,	%42,	r2
and	2,		40,		r41

or	r1,		r2,		r3
or	%21,	%42,	r2
or	2,		40,		r4

xor	r1,		r2,		r3
xor	%21,	%42,	r2
xor	2,		40,		r4

zjmp %21

ldi	r1,		r1,		r1
ldi	%1,		%50,	r2
ldi	22,		%50,	r3

sti	r1,		r3,		r4
sti	r2,		%5,		%21
sti	r3,		2,		r4

fork	%100

lld		%21,		r2
lld		2,			r3

lldi	r1,	r2,	r5
lldi	%21,	%42,	r4
lldi	1,	r2,	r5

lfork	%42

aff		r5
