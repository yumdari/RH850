objs\r_cg_systeminit.o: src\smc_gen\general\r_cg_systeminit.c \
 src\smc_gen\general\r_cg_macrodriver.h device\iodefine.h \
 src\smc_gen\general\r_cg_userdefine.h \
 src\smc_gen\Config_CSIG0\Config_CSIG0.h src\smc_gen\general\r_cg_csig.h \
 src\smc_gen\Config_PORT\Config_PORT.h src\smc_gen\general\r_cg_port.h \
 src\smc_gen\general\r_cg_cgc.h

:cmdList=ccv850 -c  -MD -Idevice -Isrc\smc_gen\Config_CSIG0 -Isrc\smc_gen\Config_PORT -Isrc\smc_gen\general -Isrc\smc_gen\r_pincfg -G -bsp generic -cpu=rh850g3kh -object_dir=objs\ -filetype.c src\smc_gen\general\r_cg_systeminit.c -o objs\r_cg_systeminit.o ; 
:cmdHash=0x87f4be48

:installDir=c:\ghs\v800.v2015.1.7\comp_201517
:installDirHash=0x433d81d7
