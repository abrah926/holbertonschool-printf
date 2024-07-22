|   |   |   |   |   |   }
 97 |   |   |   |   |   |   count += digits;
 98 |   |   |   |   |   }
 99 |   |   |   |   }
100 |   |   |   }
101 |   |   |   else if (*format == 's')
102 |   |   |   {
103 |   |   |   |   char *str = va_arg(args, char *);
104 |   |   |   |   int str_len = 0;
105
106 |   |   |   |   if (str == NULL)
107 |   |   |   |   {
108 |   |   |   |   |   str = "(null)";
109 |   |   |   |   }
110
111 |   |   |   |   while (str[str_len] != '\0')
112 |   |   |   |   |   str_len++;
113
114 |   |   |   |   write(1, str, str_len);
115 |   |   |   |   count += str_len;
116 |   |   |   }
117 |   |   |   else
118 |   |   |   {
119 |   |   |   |   _putchar('%');
120 |   |   |   |   _putchar(*format);
121 |   |   |   |   count += 2;
122 |   |   |   }
123 |   |   }
124 |   |   format++;
125 |   }
126
127 |   va_end(args);
128
129 |   return (count);
130 }
131
~
~
~
~
