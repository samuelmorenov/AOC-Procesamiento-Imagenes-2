/***************************************************************************
 *   Copyright (C) 2008 by pilar   *
 *   pilarb@unex.es   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/***************************************************************************
 * Implementacion de los metodos de imageprocess.h
 *
 * @version 2.1
 * @author
 * Samuel Moreno Vincent
 *
 * Asignatura Administración Y Organización De Computadores
 * Curso 15/16
 ***************************************************************************/

#include "imageprocess.h"

void imageprocess::rotar(uchar * imgO, uchar * imgD, float angle)
{                               //%0            %1          %2
    short cw;       //%3
    int sin1000;   //%4
    int cos1000;    //%5
    int fO;         //%6
    int cO;         //%7

    sin1000 = sin(angle)*1000.;
    cos1000 = cos(angle)*1000.;

	asm volatile(
        "fstcw %3               \n\t"
        "fwait                  \n\t"
        "mov %3, %%ax           \n\t"
        "and $0xf3ff, %%ax      \n\t"
        "or $0x0c00, %%ax       \n\t"
        "push %%eax             \n\t"
        "fldcw (%%esp)          \n\t"
        "pop %%eax              \n\t"


        //Insertar aquí el código del procedimiento:
        // // // // // // // // // // // // // // //
                "movl %0,%%esi                      \n\t"   //esi = dirOrig = imgO
                "movl %1,%%edi                      \n\t"   //edi = dirDest = imgD

                "movl $0,%%ecx                      \n\t"   //ecx = fD
                "ForRotar1:                         \n\t"
                    "movl $0,%%ebx                  \n\t"   //ebx = cD
                    "ForRotar2:                     \n\t"
                        "movl %%ebx,%%eax           \n\t"   //eax = cD
                        "subl $400,%%eax            \n\t"   //eax = cD-400
                        "imull %4,%%eax             \n\t"   //eax = sin1000*(cD-­400)

                        "movl %%ecx,%%edx           \n\t"   //edx = fD
                        "subl $400,%%edx            \n\t"   //edx = fD+400
                        "imull %5,%%edx             \n\t"   //edx = Cos1000*(fD­-400)

                        "addl %%edx,%%eax           \n\t"   //eax = (sin1000*(cD-­400) + cos1000*(fD­-400))

                        "push %%ebx                 \n\t"
                        "movl $1000,%%ebx           \n\t"
                        "movl $0,%%edx              \n\t"
                        "cltd                       \n\t"
                        "idiv %%ebx                 \n\t"   //eax = (sin1000*(cD-­400) + cos1000*(fD­-400))/1000
                        "addl $240,%%eax            \n\t"
                        "movl %%eax,%6              \n\t"   //fO = fO + 240
                        "pop %%ebx                  \n\t"



                        "movl %%ebx,%%eax           \n\t"
                        "subl $400,%%eax            \n\t"
                        "imull %5,%%eax             \n\t"
                        "movl %%ecx,%%edx           \n\t"
                        "subl $400,%%edx            \n\t"
                        "imull %4,%%edx             \n\t"

                        "subl %%edx,%%eax           \n\t"
                        "push %%ebx                 \n\t"
                        "movl $0,%%edx              \n\t"
                        "movl $1000,%%ebx           \n\t"
                        "cltd                       \n\t"
                        "idiv %%ebx                 \n\t"   //eax = (cos1000*(cD-­400) – sin1000*(fD­-400))/1000

                        "addl $320,%%eax            \n\t"
                        "movl %%eax,%7              \n\t"   //cO = cO + 320;
                        "pop %%ebx                  \n\t"



                        "cmpl $0,%6                 \n\t"
                        "jl ElseRotar               \n\t"
                        "cmpl $0,%7                 \n\t"
                        "jl ElseRotar               \n\t"
                        "cmpl $480,%6               \n\t"
                        "jge ElseRotar              \n\t"
                        "cmpl $640,%7               \n\t"
                        "jge ElseRotar              \n\t"
                        "IfRotar:                   \n\t"       //Si(fO>=0 y fO<480 y cO>=0 y cO <640)
                            "movl $640,%%eax            \n\t"
                            "imull %6,%%eax             \n\t"
                            "addl %7,%%eax              \n\t"
                            "movl %%eax,%%edx           \n\t"   //eax = fO*640+cO
                            "movl $0,%%eax              \n\t"   //indiceO = eax
                            "movb (%%esi,%%edx),%%al    \n\t"
                            "movb %%al,(%%edi)          \n\t"   //[dirDest]=[dirOrig+indiceO];
                            "jmp FinElseRotar           \n\t"

                        "ElseRotar:                 \n\t"
                            "movb $0,(%%edi)        \n\t"   //[dirDest]=0;
                            "FinElseRotar:          \n\t"


                        "incl %%edi                 \n\t"   //dirDest++
                        "incl %%ebx                 \n\t"   //cD++
                        "cmpl $800,%%ebx            \n\t"
                        "jl ForRotar2               \n\t"   //Para(cD=0; cD<800; cD++)
                    "FinForRotar2:                  \n\t"

                    "incl %%ecx                     \n\t"   //fD
                    "cmpl $800,%%ecx                \n\t"
                    "jl ForRotar1                   \n\t"   //Para(fD=0; fD<800; fD++)
                "FinForRotar1:"

        // // // // // // // // // // // // // // //
        "fldcw %3           \n\t"

        :
        : "m" (imgO), "m" (imgD), "m" (angle), "m" (cw), "m" (sin1000), "m" (cos1000), "m" (fO), "m" (cO)
        : "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory"

	);


}

void imageprocess::zoom(uchar * imgO, uchar * imgD, float s, int dx, int dy)
{//                               %0            %1       %2      %3    e  %4
    short cw;       //%5
    int sInt;       //%6
    int cO;         //%7
    int fO;         //%8
    int ampliar;    //%9

    if(s>=1)
    {
        sInt = s;
        ampliar = 1;
    }
    else
    {
        sInt = rint(1./s);
        ampliar = 0;
    }

	asm volatile(
        "fstcw %5\n\t"
        "fwait\n\t"
        "mov %5, %%ax\n\t"
        "and $0xf3ff, %%ax\n\t"
        "or $0x0c00, %%ax\n\t"
        "push %%eax\n\t"
        "fldcw (%%esp)\n\t"
        "pop %%eax\n\t"


        //Insertar aquí el código del procedimiento
        // // // // // // // // // // // // // // //
                "movl %0,%%esi                  \n\t"   //esi = dirOrig = imgO
                "movl %1,%%edi                  \n\t"   //edi = dirDest = imgD

                "movl $0,%%ecx                  \n\t"   //ecx = fD
                "ForZoom1:                      \n\t"

                    "cmpl $1,%7                 \n\t"
                    "je IfZoom1                 \n\t"
                    "jmp ElseZoom1              \n\t"
                    "IfZoom1:                   \n\t"   //Si1 (ampliar)
                        "movl %%ecx,%%eax       \n\t"       //eax = fD
                        "addl %4,%%eax          \n\t"       //eax = fD+dy
                        "cltd                   \n\t"
                        "idivl %6               \n\t"       //eax = (fD+dy)/sInt
                        "movl %%eax,%8          \n\t"       //fO = eax
                        "jmp FinElseZoom1       \n\t"

                    "ElseZoom1:                 \n\t"   //Else1
                        "movl %%ecx,%%eax       \n\t"       //eax = fD
                        "addl %4,%%eax          \n\t"       //eax = fD+dy
                        "imull %6,%%eax         \n\t"       //eax = (fD+dy)*sInt
                        "movl %%eax,%8          \n\t"       //fO = eax
                        "FinElseZoom1:          \n\t"


                    "movl $0,%%ebx              \n\t"   //ebx = cD
                    "ForZoom2:                  \n\t"

                        "cmpl $1,%7             \n\t"
                        "je IfZoom2             \n\t"
                        "jmp ElseZoom2          \n\t"
                        "IfZoom2:               \n\t"   //Si2 (ampliar)
                            "movl %%ebx,%%eax   \n\t"
                            "addl %3,%%eax      \n\t"
                            "cltd               \n\t"
                            "idivl %6,%%eax     \n\t"
                            "movl %%eax,%9      \n\t"   //cO = (cD+dx)/sInt;
                            "jmp FinElseZoom2   \n\t"

                        "ElseZoom2:             \n\t"   //Else2
                            "movl %%ebx,%%eax   \n\t"
                            "addl %3,%%eax      \n\t"
                            "imull %6,%%eax     \n\t"
                            "movl %%eax,%9      \n\t"   //cO = (cD+dx)*sInt;
                            "FinElseZoom2:      \n\t"

                        "cmpl $0,%8             \n\t"
                        "jl ElseZoom3           \n\t"
                        "cmpl $0,%9             \n\t"
                        "jl ElseZoom3           \n\t"
                        "cmpl $800,%8           \n\t"
                        "jge ElseZoom3          \n\t"
                        "cmpl $800,%9           \n\t"
                        "jge ElseZoom3          \n\t"
                        "IfZoom3:               \n\t"       //Si3 (fO>=0 y fO<800 y cO>=0 y cO <800)
                            "movl $800,%%eax            \n\t"   //eax =  800
                            "imull %8,%%eax             \n\t"   //eax =  800*fO
                            "addl %9,%%eax              \n\t"   //eax =  fO*800 + cO
                            "movl %%eax,%%edx           \n\t"
                            "movl $0,%%eax              \n\t"
                            "movb (%%esi,%%edx),%%al    \n\t"
                            "movb %%al,(%%edi)          \n\t"
                            "jmp FinElseZoom3           \n\t"

                        "ElseZoom3:             \n\t"
                            "movb $0,(%%edi)    \n\t"
                            "FinElseZoom3:      \n\t"


                        "incl %%edi             \n\t"   //dirDest++
                        "incl %%ebx             \n\t"   //cD++
                        "cmpl $640,%%ebx        \n\t"
                        "jl ForZoom2            \n\t"   //Para2(cD=0; cD<640; cD++)
                    "FinForZoom2:               \n\t"


                    "incl %%ecx                 \n\t"   //fD++
                    "cmpl $480,%%ecx            \n\t"
                    "jl ForZoom1                \n\t"   //Para1(fD=0; fD<480; fD++)
                "FinFOrZoom1:                   \n\t"
        // // // // // // // // // // // // // // //


        "fldcw %5\n\t"



        :
        : "m" (imgO), "m" (imgD), "m" (s), "m" (dx), "m" (dy), "m" (cw), "m" (sInt), "m" (ampliar), "m" (fO), "m" (cO)
        : "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory"

	);

}

void imageprocess::zoomMejorado(uchar * imgO, uchar * imgD, float s, int dx, int dy)
{
    int sInt;

    if(s<=1.)
        zoom(imgO, imgD, s, dx, dy);
    else
    {
        sInt = s;
        asm volatile(
            "\n\t"

                    //-------------------------------------------//
                    //-------------------------------------------//
                    //------------------OPCIONAL-----------------//
                    //-------------------------------------------//
                    //-------------------------------------------//
                    //-------------------------------------------//
            :
            : "m" (imgO), "m" (imgD), "m" (s), "m" (dx), "m" (dy), "m" (sInt)
            : "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory"

        );
    }

}

void imageprocess::volteoHorizontal(uchar * imgO, uchar * imgD)
{

	asm volatile(
                //-------------------------------------------//
                //-------------------------------------------//
                //------------------Terminado----------------//
                //-------------------------------------------//
                //-------------------------------------------//
                //-------------------------------------------//
        "movl %0, %%esi         \n\t"   //esi = dirOrig = imgO;
        "movl %1, %%edi         \n\t"   //edi = dirDest = imgD;
        "movl $639, %%eax        \n\t"
        "addl %%eax, %%esi      \n\t"   //eax = dirOrig + 639
        "movl $0, %%edx          \n\t"   //edx = f = 0
        "ForVH1:                    \n\t"   //Para(f=0; f<480; f++)

            "movl $0, %%ecx          \n\t"   //ecx = c = 0
            "ForVH2:                    \n\t"   //Para(c=0; c<640; c++)

                "movb (%%esi), %%al     \n\t"
                "movb %%al, (%%edi)     \n\t"   //[dirDest]=[dirOrig]
                "decl %%esi             \n\t"   //dirOrig--­­;
                "incl %%edi             \n\t"   //dirDes++
                "incl %%ecx             \n\t"   //c++
                "cmpl $640, %%ecx       \n\t"
            "jne ForVH2              \n\t"

            "movl $1280, %%eax       \n\t"
            "addl %%eax, %%esi       \n\t"   //dirOrig=dirOrig+1280;
            "incl %%edx             \n\t"   //d++
            "cmpl $480, %%edx       \n\t"
        "jne ForVH1              \n\t"


		:
		: "m" (imgO),	"m" (imgD)
        : "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory"
	);


}

void imageprocess::volteoVertical(uchar * imgO, uchar * imgD)
{

    asm volatile(
                //-------------------------------------------//
                //-------------------------------------------//
                //------------------Terminado----------------//
                //-------------------------------------------//
                //-------------------------------------------//
                //-------------------------------------------//
                "movl %0, %%esi                 \n\t"   //esi = dirOrig = imgO;
                "movl %1, %%edi                 \n\t"   //edi = dirDest = imgD;
                "movl $640, %%eax               \n\t"
                "movl $479, %%ebx               \n\t"
                "mull %%ebx                     \n\t"
                "addl %%eax, %%esi              \n\t"   //eax = dirOrig + 479*640;
                "movl $0, %%edx                 \n\t"   //edx = f = 0
                "ForVV1:                        \n\t"   //Para(f=0; f<480; f++)

                    "movl $0, %%ecx             \n\t"   //ecx = c = 0
                    "ForVV2:                    \n\t"   //Para(c=0; c<640; c++)

                        "movb (%%esi), %%al     \n\t"
                        "movb %%al, (%%edi)     \n\t"   //[dirDest]=[dirOrig]
                        "incl %%esi             \n\t"   //dirOrig--­­;
                        "incl %%edi             \n\t"   //dirDes++
                        "incl %%ecx             \n\t"   //c++
                        "cmpl $640, %%ecx       \n\t"
                    "jne ForVV2                 \n\t"

                    "movl $1280, %%eax          \n\t"
                    "subl %%eax, %%esi          \n\t"   //dirOrig=dirOrig-1280;
                    "incl %%edx                 \n\t"   //d++
                    "cmpl $480, %%edx           \n\t"
                "jne ForVV1                     \n\t"


        :
        : "m" (imgO),	"m" (imgD)
        : "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory"
    );

}

void imageprocess::iluminarLUT(uchar * tablaLUT, uchar gW)
{
    asm volatile(
                //-------------------------------------------//
                //-------------------------------------------//
                //------------------Terminado----------------//
                //-------------------------------------------//
                //-------------------------------------------//
                //-------------------------------------------//

                "movl %0, %%esi                 \n\t"   //esi = tablaLUT
                "movzbl %1, %%ebx               \n\t"   //ebx = gW
                "movl $0, %%ecx                 \n\t"   //ecx = g


                "cmpb $0, %%bl                  \n\t"
                "je ForILut2                    \n\t" //si gW == 0 saltar a segundo buble


                "ForILut1:                      \n\t"

                    "movl $255, %%edx           \n\t"   //edx = 255
                    "movl %%ecx, %%eax          \n\t"
                    "mull %%edx                 \n\t"   //eax = g*255
                    "cltd                       \n\t"
                    "divl %%ebx                 \n\t"   //eax = (g*255)/gW
                    "movb %%al, (%%esi, %%ecx)  \n\t"   //[dirLUT+g] = (g*255)/gW



                    "incl %%ecx                 \n\t"
                    "cmpl %%ebx, %%ecx          \n\t"
                "jl ForILut1                    \n\t"

                "ForILut2:                      \n\t"

                    "movb $255, (%%esi, %%ecx)  \n\t"   //[dirLUT+g] = 255;

                    "incl %%ecx                 \n\t"
                    "cmpl $256, %%ecx           \n\t"
                "jl ForILut2                    \n\t"



        :
        : "m" (tablaLUT), "m" (gW)
        : "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory"
    );

}

void imageprocess::oscurecerLUT(uchar * tablaLUT, uchar gB)
{
    asm volatile(
                //-------------------------------------------//
                //-------------------------------------------//
                //------------------Terminado----------------//
                //-------------------------------------------//
                //-------------------------------------------//
                //-------------------------------------------//

                "movl %0, %%esi                 \n\t"   //esi = tablaLUT
                "movzbl %1, %%ebx               \n\t"   //ebx = gB
                "movl $0, %%ecx                 \n\t"   //ecx = g
                "ForOLut1:                      \n\t"
                    "movb $0, (%%esi, %%ecx)    \n\t"
                    "incl %%ecx                 \n\t"
                    "cmpl %%ebx, %%ecx          \n\t"
                "jl ForOLut1                    \n\t"

                "movl %%ebx, %%ecx              \n\t"
                "incl %%ecx                     \n\t"   //ecx = g=gB+1
                "ForOLut2:                      \n\t"
                    "cmpl $255, %%ebx           \n\t"
                    "jge FinForOLut2            \n\t"

                    "movl %%ecx, %%eax          \n\t"
                    "movl %%ebx, %%edx          \n\t"
                    "subl %%edx, %%eax          \n\t"   //eax = g-gB
                    "movl $255, %%edx           \n\t"
                    "mull %%edx                 \n\t"   //eax = (g­gB)*255)


                    "movl $255, %%edx           \n\t"   //edx = 255
                    "pushl %%eax                \n\t"
                    "movzbl %%bl, %%eax         \n\t"
                    "subl %%eax, %%edx          \n\t"   //edx = (255­-gB)
                    "popl %%eax                 \n\t"


                    "divb %%dl                  \n\t"   //al= ((g­-gB)*255)/(255-­gB)

                    "movb %%al, (%%esi, %%ecx)  \n\t"   //[dirLUT+g] = ((g-­gB)*255)/(255­-gB);

                    "incl %%ecx                 \n\t"   //g++
                    "cmpl $256, %%ecx           \n\t"
                    "jl ForOLut2                \n\t"   //Para(g=gB+1; g<256; g++)
                "FinForOLut2:                   \n\t"
        :
        : "m" (tablaLUT), "m" (gB)
        : "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory"
    );

}

void imageprocess::iluminarLUTMejorado(uchar * tablaLUT, uchar gW)
{
    asm volatile(
                "\n\t"

                //-------------------------------------------//
                //-------------------------------------------//
                //------------------OPCIONAL-----------------//
                //-------------------------------------------//
                //-------------------------------------------//
                //-------------------------------------------//
        :
        : "m" (tablaLUT), "m" (gW)
        : "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory"
    );

}

void imageprocess::oscurecerLUTMejorado(uchar * tablaLUT, uchar gB)
{
    asm volatile(
        "\n\t"

                //-------------------------------------------//
                //-------------------------------------------//
                //------------------OPCIONAL-----------------//
                //-------------------------------------------//
                //-------------------------------------------//
                //-------------------------------------------//
        :
        : "m" (tablaLUT), "m" (gB)
        : "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory"
    );

}

void imageprocess::aplicarTablaLUT(uchar * tablaLUT, uchar * imgO, uchar * imgD)
{
    asm volatile(
                //-------------------------------------------//
                //-------------------------------------------//
                //------------------Terminado----------------//
                //-------------------------------------------//
                //-------------------------------------------//
                //-------------------------------------------//

        "movl %0, %%edx                 \n\t"   //edx = dirLUT = tablaLUT;
        "movl %1, %%esi                 \n\t"   //esi = dirOrig = imgO;
        "movl %2, %%edi                 \n\t"   //edi = dirDest = imgD;
        "movl $640*480, %%ecx           \n\t"   //ecx = p;
        "ForATLut:                      \n\t"
            "movzbl (%%esi), %%eax      \n\t"   //eax = gOrig = [dirOrig];
            "movb (%%edx, %%eax), %%bl  \n\t"   //bl = gDest = [dirLUT + gOrig];
            "movb %%bl, (%%edi)         \n\t"   //[dirDest] = gDest;
            "incl %%esi                 \n\t"   //dirOrig++;
            "incl %%edi                 \n\t"   //dirDest++;

        "loop ForATLut                  \n\t"   //Para(p=0; p<640*480; p++)
        :
        : "m" (tablaLUT), "m" (imgO), "m" (imgD)
        : "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory"
    );

}
