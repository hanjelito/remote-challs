#!/usr/bin/python

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    xlogin.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 16:37:42 by juan-gon          #+#    #+#              #
#    Updated: 2020/04/06 17:29:21 by juan-gon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

if len(sys.argv) == 2:
    src = sys.argv[1]
    if (src).isalpha() == True or src.find(' ') > -1:
        code = {
            "a": ".-", "b": "-...", "c": "-.-.", "d": "-..", "e": ".", "f": "..-.", 
            "g": "--.", "h": "....", "i": "..", "j": ".---", "k": "-.-", "l": ".-..", 
            "m": "--", "n": "-.", "o": "---", "p": ".__.", "q": "--.-",
            "r": ".-.", "s": "...", "t": "-", "u": "..-", "v": "...-", "w": ".--",
            "x": "-..-", "y": "-.--", "z": "--.."
        }
        text_cod = ""
        
        for c in src:
            
            if c != " " and c.lower() in code:
                text_cod += code[c.lower()]
            elif c == " ":
                text_cod += " "
            else:
                text_cod += c
            
        print("{}".format(text_cod))
    else: 
        print("usage: " + sys.argv[0] + " <a-zA-Z string>")
else: 
    print("usage: " + sys.argv[0] + " <a-zA-Z string>")
