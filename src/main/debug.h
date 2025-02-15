/*

    Debugging Modul

    es sind zwei Möglichkeiten vorgesehen:
    * UART - über USART feature (RS232) des Chips mit Settings 3840 / 8N1
    * SIMUL - über den Simulator

    TODO:   Trace-Mode

*/


//#define DEBUG_UART
#define DEBUG_SIMUL


#ifdef DEBUG

void debug_c(unsigned char);
int debug_printf (char const*, ...);
#define error(M,...) debug_printf("0 %s:%d: " M "\n\r",__FILE__,__LINE__,##__VA_ARGS__)
#define warn(M,...) debug_printf("1 %s:%d: " M "\n\r",__FILE__,__LINE__,##__VA_ARGS__)
#define info(M,...) debug_printf("2 %s:%d: " M "\n\r",__FILE__,__LINE__,##__VA_ARGS__)
#define debug(M,...) debug_printf("3 %s:%d: " M "\n\r",__FILE__,__LINE__,##__VA_ARGS__)
#define debugn(M,...) debug_printf("3 %s:%d: " M,__FILE__,__LINE__,##__VA_ARGS__)
#define debugc(M,...) debug_printf(M,##__VA_ARGS__)
#define debugnl(M,...) debug_printf(M "\n\r")

#else
#ifndef debug
void debug_default(char const*, ...);
#define debug(M,...)
#define debugn(M,...)
#define debugc(M,...)
#define debugnl(M,...)
#endif
#endif

