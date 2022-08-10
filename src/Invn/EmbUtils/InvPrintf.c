/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

#include "InvPrintf.h"

/** @brief  Convert a number into a string
 *
 * This function converts a numerical value into a string.
 * @warning This function is not thread safe as it uses a static buffer
 *
 * @param[in] num           Numerical value
 * @param[in] base          Base for the string conversion, should be 10 or 16
 * @param[out] length       Length of the converted string (must be initialized first)
 *
 * @return Pointer to the converted string (point to a static buffer)
 */
static char *convert2string(unsigned int num, int base, int *length)
{
    static char buf[16];
    char *ptr;

    // Start from the end of the buffer - insert the null termination
    ptr=&buf[sizeof(buf)-1];
    *ptr='\0';

    // Insert digits starting from the right
    do
    {
        *--ptr = "0123456789ABCDEF"[num % base];
        num /= base;
        ++(*length);
    }
    while(num != 0);

    // Return the position of the first digit
    return(ptr);
}

int inv_vprintf(const char *fmt, va_list args)
{
    char *str , *sval;
    int ival, sign;
    int length = 0;
    char *num2char;
    char padChar, signChar, ch;
    int width;
    int i;
    int byteswritten = 0;

    for(str = (char *)fmt; *str; str++)
    {
        // Check for format specifier
        if(*str!='%')
        {
            if(INV_PRINTF_PUTCHAR_HOOK(*str) != *str)
                goto end;
            ++byteswritten;
            continue;
        }
        else 
        {
            str++;
            width = length = sign = 0;
            signChar = '\0';

            // Default padding is space
            padChar = ' ';

            if (*str == '\0') break;

            if (*str == '-') 
            {
                str++;
            }

            // Check if '0' padding is required
            if (*str == '0')
            {
                str++;
                padChar = '0';
            }

            // Get the width field
            for ( ; *str >= '0' && *str <= '9'; str++) 
            {
                width *= 10;
                width += *str - '0';
            }

            // Process the data type
            switch(*str)
            {
            case 'c':
                ch = (char)va_arg(args,int);
                
                INV_PRINTF_PUTCHAR_HOOK(ch);
                ++byteswritten;
                break;

            case 'd':
            case 'D':
                ival=va_arg(args,int);
                if(ival < 0)
                {
                    ival=-ival;
                    sign = 1;
                    signChar = '-';
                }

                num2char = convert2string(ival, 10, &length);

                if (length >= width) 
                    width = 0;
                else 
                    width -= (length+sign);

                // If 0 padding and -ve number, print the sign first
                if (sign && padChar == '0')
                {
                    if(INV_PRINTF_PUTCHAR_HOOK(signChar) != signChar)
                        goto end;
                    ++byteswritten;
                }

                // Print the leftover 'width' padding
                while(width)
                {
                    if(INV_PRINTF_PUTCHAR_HOOK(padChar) != padChar)
                        goto end;
                    ++byteswritten;
                    width--;
                }

                // If no padding and -ve number, print the sign now
                if(sign  && padChar == ' ')
                {
                    if(INV_PRINTF_PUTCHAR_HOOK(signChar) != signChar)
                        goto end;
                    ++byteswritten;
                }

                for (i = 0; i < length; i++)
                {
                    if(INV_PRINTF_PUTCHAR_HOOK(num2char[i]) != num2char[i])
                        goto end;
                    ++byteswritten;
                }
                break;

            case 'x':
            case 'X':
                ival=va_arg(args,int);
                num2char = convert2string(ival, 16, &length);
                if (length >= width) 
                    width = 0;
                else 
                    width -= length;

                while(width)
                {
                    if(INV_PRINTF_PUTCHAR_HOOK(padChar) != padChar)
                        goto end;
                    ++byteswritten;
                    width--;
                }
                for (i = 0; i < length; i++)
                {
                    if(INV_PRINTF_PUTCHAR_HOOK(num2char[i]) != num2char[i])
                        goto end;
                    ++byteswritten;
                }
                break;

            case 's':
            case 'S':
                sval = va_arg(args,char*);

                for(; *sval; sval++)
                    length++;
                if (length >= width) 
                    width = 0;
                else 
                    width -= length;

                while(width)
                {
                    if(INV_PRINTF_PUTCHAR_HOOK(padChar) != padChar)
                        goto end;
                    ++byteswritten;
                    width--;
                }
                sval -= length;
                for (i = 0; i < length; i++)
                {
                    if(INV_PRINTF_PUTCHAR_HOOK(sval[i]) != sval[i])
                        goto end;
                    ++byteswritten;
                }
                break;

            default:
                if(INV_PRINTF_PUTCHAR_HOOK(*str) != *str)
                    goto end;
                ++byteswritten;
                break;
            }
        }
    }

end:    
    va_end(args);

    return byteswritten;
}
