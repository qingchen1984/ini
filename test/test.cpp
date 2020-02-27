//
// Created by qingchen on 20-2-27.
//



#include <iostream>
#include <stdio.h>
#include "../src/ini.h"


using namespace std ;
using std::cout ;
using std::cin ;
using std::endl ;

/*

ini_t*      ini_load(const char *filename);
void        ini_free(ini_t *ini);
const char* ini_get(ini_t *ini, const char *section, const char *key);
int         ini_sget(ini_t *ini, const char *section, const char *key, const char *scanfmt, void *dst);

 */

int main(int argc,char* argv[])
{

    ini_t* cfgfile = ini_load("./watchdog.conf") ;

    const char* pkgsum = ini_get(cfgfile,"pkgcnt","pkgsum") ;

    printf("pkgsum is %s\n",pkgsum) ;


    const char* runpath1 = ini_get(cfgfile,"plugin1","runpath1") ;
    const char* exename1 = ini_get(cfgfile,"plugin1","exename1") ;
    const char* runcmd1 = ini_get(cfgfile,"plugin1","runcmd1") ;
    const char* realruncmd1 = ini_get(cfgfile,"plugin1","realruncmd1") ;

    cout<<"runpath1:    "<<runpath1<<"\n"<<"exename1:     "<<exename1<<endl ;
    cout<<"runcmd1:    "<<runcmd1<<"\n"<<"realruncm1:     "<<realruncmd1<<endl ;

    ini_sget(cfgfile,"plugin1","runpath1",NULL,"/tmp/aa/accctrl") ;
    cout<<"runpath1:    "<<runpath1<<endl ;




    return 0 ;
}
