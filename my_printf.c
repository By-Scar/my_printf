#include <stdarg.h>

int             my_printf(char *format, ...)
{
  va_list       ap;
  int           i;

  i = 0;
  va_start(ap, format);
  while (format[i] != 0)
    {
      if (format[i] == '%')
        {
          if (format[i + 1] == 's')
            my_putstr(va_arg(ap, char *));
          else if (format[i + 1] == 'd' || format[i + 1] == 'i')
            my_put_nbr(va_arg(ap, int));
          else if (format[i + 1] == 'c')
            my_putchar(va_arg(ap, int));
          else
            my_putchar(format[i + 1]);
          i++;
        }
      else
        my_putchar(format[i]);
      i++;
    }
  va_end(ap);
  return (0);
}
