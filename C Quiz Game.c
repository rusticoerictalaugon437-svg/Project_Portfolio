#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


void loadingscreen();
void loading_screen1();
void loading_screen2();
void loading_screen3();
void loading_screen4();

void loading_texts(int hd);

void main_menu();

void per_info();
void input_username_display();
void main_menu_charot_button();

void easter_itlog();
void opt();

void choose_diff1();
void choose_diff1_txt_disp();

void easy_diff1(int *a, int *scr, int diff1); 
void easy_que1(int a, int *scr, int diff1);

void med_diff1(int *b, int *scr, int diff); 
void med_que1(int b, int *scr, int diff1);

void hard_diff1(int *c, int *scr, int diff1); 
void hard_que1(int c, int *scr, int diff1);

void inst_txt_disp();
void inst_txt_disp1();
void answer_txt_disp();
void correct_ans();
void incorrect_ans();
void correct_ans_final();
void incorrect_ans_final();

void game_opt();
void game_restart();
void play_again();


void exit_prog();

void shuffle_array(char arr[][2024], char choices[][2024], char answers[][2024], int n);

char ez_q1_chc [10][2024] = {
    {"\nA.Denis Ritchey\nB. Dennison Ritchie\nC. Dennis Ritchie\nD. Danis Ritchie"},
    {"\nA. to create a flexible and efficient programming language that could be used to develop the Unix operating system.\nB. To create a language focused on web development and internet protocols.\nC. To develop a language optimized for scientific computing and mathematical operations.\nD. To design a versatile and powerful language suitable for system programming tasks."},
    {"\nA.1976\nB.1972\nC.1973\nD.1970"},
    {"\nA. BPLC (Basic Programming Language Compiler)\nB. BCPL (Basic Combined Programming Language)\nC. BCPL (Basic Compiled Programming Language)\nD. BCLP (Basic Combined Language for Programming) "},
    {"\nA. It marked the first implementation of object-oriented programming concepts in C.\nB. It was the catalyst for the development of the C Standard Library.\nC. It demonstrated the efficiency of memory management techniques in C.\nD. It is often used as a simple introductory program to demonstrate the basic syntax and structure of the language"},
    {"\nA. 1974\nB. 1972\nC. 1978\nD. 1976"},
    {"\nA. Standardization of library functions like <stdio.h> and <stdlib.h>.\nB. Standardization of library functions like <stdio,h> and <stdlib,h>\nC. Introduction of header files and preprocessing directives.\nD. Support for comments using // for single-line comments and /* */ for multi-line comments."},
    {"\nA. It  was driven by the need for standardization and the desire to address shortcomings and ambiguities present in the previous C78/C88 standard.\nB.  It  was driven by the need for standardization and the desire to address shortcomings and ambiguities present in the previous C79/C80 standard.\nC.It was driven by the need for standardization and the desire to address shortcomings and ambiguities present in the previous C89/C90 standard.\nD. It  was driven by the need for standardization and the desire to address shortcomings and ambiguities present in the previous C88/C98 standard."},
    {"\nA. It provided a foundation for operating systems, system software, and embedded systems.\nB. It made an impact on modern computing through its advancements in artificial intelligence and machine learning algorithms.\nC. It significantly shaped modern computing by revolutionizing user interface design and graphical rendering techniques.\nD. It  greatly influenced modern computing through its contributions to quantum computing and cryptographic protocols."},
    {"\nA. GCC (GNU Compiler Collection)\nB. Clang\nC. COBOL\nD. Turbo C++"},
};

char med_q1_chc [10][2024] = {
    {"\nA.`scanf()` does not consume the newline character from the input stream, while `fgets()` includes the newline character in the string it reads.\nB. `scanf()` is specifically designed for reading strings from input, while `fgets()` is primarily used for numerical input parsing.\nC. `scanf()` is more efficient for reading large amounts of text from input compa to `fgets()`.\nD. `fgets()` allows for more precise control over formatting options compa to `scanf()`."},
    {"\nA. The `&` operator in `scanf(\"%d\", &num)` is used to indicate that the value of `num` is being passed by reference to `scanf()`, enabling it to directly access the value.\nB. In `scanf(\"%d\", &num)`, the `&` operator is used to denote the end of the format specifier and the beginning of the variable name.\nC. The `&` operator in `scanf(\"%d\", &num)` is used to perform bitwise AND operation between the format specifier and the value of `num`, ensuring compatibility for input conversion.\n D.The `&` operator in `scanf(\"%d\", &num)` is used to pass the memory address of the variable `num` to `scanf()`, allowing it to directly modify the value sto at that address."},
    {"\nA.`sleep()` suspends the program execution for a specified number of nanoseconds, while `usleep()` suspends it for a specified number of microseconds.\nB.`sleep()` suspends the program execution for a specified number of microseconds, while `usleep()` suspends it for a specified number of nanoseconds.\nC.`sleep()` suspends the program execution for a specified number of seconds, while `usleep()` suspends it for a specified number of microseconds.\nD.`sleep()` suspends the program execution for a specified number of nanoseconds, while `usleep()` suspends it for a specified number of seconds."},
    {"\nA.`scanf()'\nB.`fgets()`\nC.`gets()`\nD. `fscanf()`"},
    {"\nA.`for' loop\nB.`while` loop\nC.`do-while` loop\nD. `switch`"},
    {"\nA.`#define'\nB.`#include`\nC.`if-def`\nD.`#error`"},
    {"\nA.`sleep()`'\nB.`usleep()`\nC.`nanosleep()`\nD.`clock_gettime()`"},
    {"\nA.`stdio.h'\nB.`stdlib.h`\nC.`math,h`\nD.`ncurses.h`"},
    {"\nA.`\\031[0;33m'\nB.`\\032[0;31m`\nC.`\\033[0;31m`\nD.`\\031[0;32m`"},
    {"\nA.No Return and No Parameter\nB.Return with Parameter\nC.Return with no. Parameter\nD.Parameter with No Return "},
};

char ez_q1[10][2024] = {
    {"Who is cited with the creation of the C programming language?\n"},
    {"What was the original purpose behind the development of C?\n"},
    {"In what year was the first version of the C programming language created?\n"},
    {"Which programming language heavily influenced the syntax and design of C?\n"},
    {"What was the significance of the \"Hello, World!\" program in the history of C?\n"},
    {"When was the first edition of \"The C Programming Language\" book, commonly refer to as K&R C, published?\n"},
    {"Key features introduced in the ANSI C standard, commonly known as C89 or C90. All choices are correct EXCEPT;\n"},
    {"What prompted the development of the C99 standard?\n"},
    {"How has the development and standardization of the C programming language influenced modern computing?\n"},
    {"These are some of the notable implementations and derivatives of the C programming language throughout its history, EXCEPT;\n"}
};

char med_q1[10][2024] = {
    {"How does scanf() and fgets() differ?\n"},
    {"What is the function of & in “scanf(“%d”, &num)?\n"},
    {"What is the difference between sleep() and usleep()?\n"},
    {"In a program that collects user data for a survey, which statement ensures accurate input while handling spaces in text responses?\n"},
    {"When developing a financial application that calculates interest rates, which loop structure ensures precision in iterative calculations?\n"},
    {"In a program responsible for processing sensor data from IoT devices, which preprocessor directive facilitates code readability and maintenance?\n"},
    {"In a program aimed at simulating real-time processes, which function provides accurate timing by pausing execution for a specified number of milliseconds?\n"},
    {"All header files are in standard library in C prog EXCEPT: \n"},
    {"What is the ANSI escape code to make the text itself color ? \n"},
    {"All are user-defined functions, EXCEPT:\n"}
};

char hard_q1[10][2024] = {
    {"\n#include <stdio.h>\n#include <math.h>\n\n#define e 2.71828\n\nint main() {\n\tfloat a, b, c, d;\n\tprintf(\"Enter input: \");\n\tscanf(\"%g\", &a);\n\tb = sqrt(3 * pow(e, a) * 19 * log(a) * 86 * sin(a)); \n\tprintf(\"The output is: %g\\n\", b); \n\treturn 0;\n}"},
    {"\n#include <stdio.h>\n#include <math.h>\nint main()\n{\n\tfloat a,b,c,d=1,i=1,f,e;\n\tprintf(\"Enter the factorial: \");\n\tscanf(\"%g\", &a);\n\tprintf(\"Enter the number for natural logarithmic: \");\n\tscanf(\"%g\", &b);\n\twhile (a >= i)\n\t{\n\t\td=i*d;\n\t\ti++;\n\t}\n\te=log(b);\n\tf=e*d;\n\tprintf(\"The output is %g\", f);\n\treturn 0;\n}"},
    {"\nint main()\n{\n\tfloat a,b;\n\tprintf(\"Enter the input: \");\n\tscanf(\"%g\", &a);\n\tb=pow(a, 2);\n\tprintf(\"The output is %g\", b);\n\treturn 0;\n}"},
    {"\n#include <stdio.h>\n\nvoid scientific_notation(double number) {\n\tint exponent = 0;\n\twhile (number >= 10.0 || number <= -10.0) {\n\t\tnumber /= 10.0;\n\t\texponent++;\n\t}\n\tprintf(\"%.2f * 10^%d\\n\", number, exponent);\n}\n\nint main() {\n\tdouble num;\n\tprintf(\"Enter a number: \");\n\tscanf(\"%lf\", &num);\n\tprintf(\"Scientific notation: \");\n\tscientific_notation(num);\n\treturn 0;\n}"},
    {"\n#include <stdio.h>\n#include <math.h>\n#define e 2.718281828f\n\nvoid scientific_notation(double c);\n\nint main() {\n\tfloat a, c;\n\tprintf(\"Find the value of y' corresponding to the value of x.\\n\");\n\tprintf(\"y = sin(2x^2) + 3x^5 + 4e^3x\\n\");\n\tprintf(\"Enter the input (x): \");\n\tscanf(\"%f\", &a);\n\tc = (2*a*(cos(pow(a, 2))))+(15 * pow(a, 4))+(12 * pow(e, (3*a)));\n\tscientific_notation(c);\n\treturn 0;\n}\n\nvoid scientific_notation(double c) {\n\tint exponent = 0;\n\twhile (c >= 10.0 || c <= -10.0) {\n\t\tc /= 10.0;\n\t\texponent++;\n\t}\n\tprintf(\"The output is %.2f * 10^%d\\n\", c, exponent);\n}"},
    {"\n#include <stdio.h>\n\nint main() {\n\tint n,a = 2, b = 1, c;\n\tprintf(\"Enter the number of terms in the Lucas Sequence: \");\n\tscanf(\"%d\", &n);\n\tprintf(\"Lucas Sequence:\\n\");\n\tprintf(\"%d, %d, \", a, b); // Print the first two terms\n\tfor (int i = 3; i <= n; i++) {\n\t\tc = a + b;\n\t\tprintf(\"%d, \", c);\n\t\ta = b;\n\t\tb = c;\n\t}\n\treturn 0;\n}"},
    {"\n#include <stdio.h>\n#include <math.h>\n\nint main() {\n\tfloat a, b, c, d;\n\tprintf(\"Total Kinetic Energy Computation\\n\");\n\tprintf(\"Enter the mass(kg): \");\n\tscanf(\"%f\", &a);\n\tprintf(\"Enter the initial velocity(m/s): \");\n\tscanf(\"%f\", &b);\n\tprintf(\"Enter the final velocity(m/s): \");\n\tscanf(\"%f\", &c);\n\td = ((a * pow(b, 2)) / 2) + ((a * pow(c, 2)) / 2);\n\tprintf(\"Total Kinetic Energy: %.2f J\\n\", d);\n\treturn 0;\n}"},
    {"\n#include <stdio.h>\n#include <math.h>\n\nint main() {\n\tfloat a, b, c, d;\n\tprintf(\"Motion in Constant Acceleration\\n\");\n\tprintf(\"Enter the initial velocity: \");\n\tscanf(\"%f\", &a);\n\tprintf(\"Enter the time: \");\n\tscanf(\"%f\", &b);\n\tprintf(\"Enter the acceleration: \");\n\tscanf(\"%f\", &c);\n\td = (a*b) + ((c*pow(b, 2))/2) ;\n\tprintf(\"The output: %.2f m\\n\", d);\n\treturn 0;\n}"},
    {"\n#include <stdio.h>\n#include <math.h>\n\nint main() {\n\tfloat a, b, c, d;\n\tprintf(\"Motion in Constant Acceleration\\n\");\n\tprintf(\"Enter the mass: \");\n\tscanf(\"%f\", &a);\n\tprintf(\"Enter the velocity: \");\n\tscanf(\"%f\", &b);\n\tprintf(\"Enter the radius: \");\n\tscanf(\"%f\", &c);\n\td = (a*pow(b, 2)) / c ;\n\tprintf(\"The output: %.2f N\\n\", d);\n\treturn 0;\n}"},
    {"\n#include <stdio.h>\n#include <math.h>\n\n#define e 2.71828\n\nint main() {\n\tfloat a, b, c, d;\n\tprintf(\"Enter input: \");\n\tscanf(\"%g\", &a);\n\tb = 10*sinh(pow(a,3))+(2*cbrt(pow(e,4)))-(49*log(a));\n\tprintf(\"The output is: %g\\n\", b); \n\treturn 0;\n}\n"}
};

char hard_sub_q[10][2024] = {
    {"\n\nIf the input is 13, what is the output?\n"},
    {"\n\nIf the output is 469.443 and the a is equal to 5, what should be the value of b?\n"},
    {"\n\nIf the output is 170569, what should be the input?\n"},
    {"\n\nIf the input should be 9268570623993120479 what should be the output?\n"},
    {"\n\nWhat would be the output if the input is 23?\n"},
    {"\n\nWhat would be the input if the last term is 1149851?\n"},
    {"\n\nWhat would be the final velocity if the initial velocity is 20 m/s, mass is 1 kg and Total KE is 420.5 J?\n"},
    {"\n\nWhat would be the value of b if the output is 630, initial velocity is 22, acceleration is 19 (up to ten thousandth)?\n"},
    {"\n\nWhat would be the value of b if the output is 514, the mass is 17, and radius is 2(up to ten thousandth?\n"},
    {"\n\nIf the input is 2, what is the output? \n"}
};

char ez_ans [10][2024] = {{'C'}, {'A'}, {'B'}, {'B'}, {'D'}, {'C'}, {'A'}, {'C'}, {'A'}, {'C'}};

char med_ans [10][2024] = {{'A'}, {'D'}, {'C'}, {'B'}, {'A'}, {'A'}, {'B'}, {'C'}, {'C'}, {'C'}};

char hard_ans [10][2024] = {{"48344.7"}, {"50"}, {"413"}, {"9.27 * 10^18"}, {"1.11 * 10^31"}, {"30"}, {"21"}, {"7.06746"}, {"7.77628"}, {"14878.4"}, };

int main() 
{
    loadingscreen();
    main_menu();
    return 0;
}

void main_menu()
{
    system("clear");
    loading_screen3(); 
    per_info();
    opt();
}

void per_info() 
{
    char ns[50];
    input_username_display();
    fgets(ns, sizeof(ns), stdin);
    ns[strcspn(ns, "\n")] = 0;
    system("clear");
    loading_screen4();
    printf("\n\n\t\t\t\t\t\t\tH");fflush(stdout);usleep(100000);
    printf("e");fflush(stdout);usleep(100000); 
    printf("l");fflush(stdout);usleep(100000);
    printf("l");fflush(stdout);usleep(100000);
    printf("o! ");fflush(stdout);usleep(100000);
    printf("%s ", ns);fflush(stdout);usleep(100000);
    printf("W");fflush(stdout);usleep(100000);
    printf("e");fflush(stdout);usleep(100000); 
    printf("l");fflush(stdout);usleep(100000);
    printf("c");fflush(stdout);usleep(100000);
    printf("o");fflush(stdout);usleep(100000);
    printf("m");fflush(stdout);usleep(100000);
    printf("e\n");fflush(stdout);usleep(100000);
}

void opt()
{
    int eme;
    main_menu_charot_button();
    scanf("%d", &eme);
    getchar();
    if (eme == 1) 
    {
        system("clear");
        loading_screen4();
        choose_diff1();   
    }
    else if (eme == 2 )
    {
        system("clear");
        exit_prog();
    } 
    else if (eme == 3 )
    {
        easter_itlog();
    } 
}


void choose_diff1() 
{
    int a = 0; 
    int b = 0;
    int c = 0;
    int scr = 0;
    int diff1;
    choose_diff1_txt_disp();
    scanf("%d", &diff1);
    while (getchar() != '\n'); 
    if (diff1 == 1) 
    {
        shuffle_array(ez_q1, ez_q1_chc, ez_ans, 10);
        easy_diff1(&a, &scr, diff1); 
    }
    if (diff1 == 2) 
    {
        shuffle_array(med_q1, med_q1_chc, med_ans ,10);
        med_diff1(&b, &scr, diff1); 
    }
    if (diff1 == 3) 
    {
        shuffle_array(hard_q1, hard_sub_q, hard_ans,10);
        hard_diff1(&c, &scr, diff1);
    }
    if (diff1 == 4)
    {
        shuffle_array(ez_q1, ez_q1_chc, ez_ans, 10);
        easy_diff1(&a, &scr, diff1); 
        shuffle_array(med_q1, med_q1_chc, med_ans ,10);
        med_diff1(&b, &scr, diff1);
        shuffle_array(hard_q1, hard_sub_q, hard_ans,10);
        hard_diff1(&c, &scr, diff1);
        system("clear");
        loading_screen4();
        printf("Your score is %d\n", scr);
        play_again();
        scr=0;
    }
}

void easy_diff1(int *a, int *scr, int diff1) 
{
    int b = 0;
    int c = 0;
    inst_txt_disp();
    while (*a < 10) {
        system("clear");
        loading_screen4();
        game_opt();
        easy_que1(*a, scr, diff1);
        (*a)++; 
    }
    if (diff1 == 1)
    {
    system("clear");
    loading_screen4();
    printf("Your score is %d\n", *scr);
    play_again();
    *scr=0;
    }
    else if (diff1 == 4)
    {
    system("clear");
    }
}

void easy_que1(int a, int *scr, int diff1) 
{
    char a1[200];
    printf("%s%s", ez_q1[a],ez_q1_chc[a]);fflush(stdout);sleep(1);
    answer_txt_disp();   
    scanf("%s", a1);
    
    if (strcasecmp(a1, "0") == 0)
    {
        a=10;
        scr = 0;
        game_restart();
    }
    
    if (strcasecmp(a1, "1") == 0)
    {
        system("clear");
        exit_prog();
        exit(0);
    }
    
     switch (a) {
        case 0:
            if (strcmp(a1, ez_ans[0]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 1:
            if (strcmp(a1, ez_ans[1]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 2:
            if (strcmp(a1, ez_ans[2]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 3:
            if (strcmp(a1, ez_ans[3]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 4:
            if (strcmp(a1, ez_ans[4]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 5:
            if (strcmp(a1, ez_ans[5]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 6:
            if (strcmp(a1, ez_ans[6]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 7:
            if (strcmp(a1, ez_ans[7]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 8:
            if (strcmp(a1, ez_ans[8]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 9:
            if (strcmp(a1, ez_ans[9]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
       
    }
    
}
    
void med_diff1(int *b, int *scr, int diff1) 
{
    inst_txt_disp();
    while (*b < 10) 
    {
        system("clear");
        loading_screen4();
        game_opt();
        med_que1(*b, scr,diff1);
        (*b)++; 
    }
   if (diff1 == 1)
    {
    system("clear");
    loading_screen4();
    printf("Your score is %d\n", *scr);
    play_again();
    *scr=0;
    }
    else if (diff1 == 4)
    {
    system("clear");
    }
}

void med_que1(int b, int *scr, int diff1) 
{
    char b1[200];
    printf("%s%s", med_q1[b], med_q1_chc[b]);fflush(stdout);sleep(1);
    answer_txt_disp();
    scanf("%s", b1);
    
    if (strcasecmp(b1, "0") == 0)
    {
        b=10;
        scr = 0;
        game_restart();
    }
    
    if (strcasecmp(b1, "1") == 0)
    {
        system("clear");
        exit_prog();
        exit(0);
    }
    
    switch (b) {
        case 0:
            if (strcmp(b1, med_ans[0]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 1:
            if (strcmp(b1, med_ans[1]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 2:
            if (strcmp(b1, med_ans[2]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 3:
            if (strcmp(b1, med_ans[3]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 4:
            if (strcmp(b1, med_ans[4]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 5:
            if (strcmp(b1, med_ans[5]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 6:
            if (strcmp(b1, med_ans[6]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 7:
            if (strcmp(b1, med_ans[7]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 8:
            if (strcmp(b1, med_ans[8]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 9:
            if (strcmp(b1, med_ans[9]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
       
    }
    
}

void hard_diff1(int *c, int *scr, int diff1) 
{
    inst_txt_disp1();
    char c1 = '\0';
    while (*c < 10) 
    {
        system("clear");
        loading_screen4();
        game_opt();
        hard_que1(*c, scr, diff1);
        (*c)++; 
    }
   if (diff1 == 1)
    {
    system("clear");
    loading_screen4();
    printf("Your score is %d\n", *scr);
    play_again();
    *scr=0;
    }
    else if (diff1 == 4)
    {
    system("clear");
    }
}

void hard_que1(int c, int *scr, int diff1) 
{
    char c1[200];
    printf("%s%s", hard_q1[c],hard_sub_q[c]);fflush(stdout);sleep(1);
    answer_txt_disp();
    fgets(c1, sizeof(c1), stdin);
    
    if (strlen(c1) > 0 && c1[strlen(c1) - 1] == '\n')
    {
        c1[strlen(c1) - 1] = '\0';
    }
    
    if (strcasecmp(c1, "0") == 0)
    {
        c=10;
        *scr = 0;
        game_restart();
    }
    
    if (strcasecmp(c1, "1") == 0)
    {
        system("clear");
        exit_prog();
        exit(0);
    }
    
     switch (c) {
        case 0:
            if (strcmp(c1, hard_ans[0]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 1:
            if (strcmp(c1, hard_ans[1]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 2:
            if (strcmp(c1, hard_ans[2]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 3:
            if (strcmp(c1, hard_ans[3]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 4:
            if (strcmp(c1, hard_ans[4]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 5:
            if (strcmp(c1, hard_ans[5]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 6:
            if (strcmp(c1, hard_ans[6]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 7:
            if (strcmp(c1, hard_ans[7]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 8:
            if (strcmp(c1, hard_ans[8]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
         case 9:
            if (strcmp(c1, hard_ans[9]) == 0) {
                correct_ans();
                *scr += 1;
            } else {
                incorrect_ans();
            }
            break;
       
    }
}

void loadingscreen()
{
    int se = 1;
    int hd = 1;
    int sd = 0;
    loading_screen1();
    while (hd < 11) 
    {
        if (se) 
        {
            system("clear");
            loading_screen1();
            hd += 1;
            sd += 20;
            loading_texts(hd);
        } 
        else 
        {
            system("clear");
            loading_screen2();
            hd += 1;
            sd += 20;
            loading_texts(hd);
        }
        se = !se;
        sleep(1);
    }
}

void loading_screen1() 
{
     printf("\t\t\t\t ____________________________________________________________________________________\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                                    _______                                         |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|  ☆      (\\___/)               |   _____|                         (\\___/)           |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|          ( o.o )                |  |                               ( o.o )      ☆  |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|           > ^ <                 |  |                                > ^ <          |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                                  |  |____                                          |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|      ☆                         |_______|                            ☆              |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                                                                                    |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                ☆        知識が増えます || 私はパワーを得る                         |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                  ____          ____    ____  ___   __ __   ___             ☆       |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                 |    | |   | |  __/   | __  | _ | |  |  | |_                       |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                 |__ \\| |___| | /___   |___| |   | |     | |___                     | \n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|  ☆                                                                ☆                |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|          (づ ᴗ _ᴗ)づ♡| Rustico Eric E. Talaugon III - BSCPE-1|(˶˃ ᵕ ˂˶)            |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                                                                              ☆     |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|____________________________________________________________________________________|\n");fflush(stdout);usleep(10000);
}

void loading_screen2() 
{
      printf("\t\t\t\t ____________________________________________________________________________________\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                                    _______                                         |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|  ☆       /\\_/\\               |   _____|                          /\\_/\\             |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|         ( o.o )                  |  |                           ( o.o )      ☆     |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|        (\'\')_(\'\')              |  |                             (\'\')_(\'\')           |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                             |  |____                                               |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|      ☆                             |_______|                        ☆              |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                                                                                    |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                ☆        知識が増えます || 私はパワーを得る                         |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                  ____          ____    ____  ___   __ __   ___             ☆       |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                 |    | |   | |  __/   | __  | _ | |  |  | |_                       |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                 |__ \\| |___| | /___   |___| |   | |     | |___                     | \n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|  ☆                                                                ☆                |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|          (づ ᴗ _ᴗ)づ♡| Rustico Eric E. Talaugon III - BSCPE-1|(˶˃ ᵕ ˂˶)            |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                                                                              ☆     |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|____________________________________________________________________________________|\n");fflush(stdout);usleep(10000);
}

void loading_screen3() 
{
   printf("\t\t\t\t ____________________________________________________________________________________\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|                        _______                                                     |\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|    ☆     (\\___/)      |  _____|                                  /\\_/\\    ☆        |   \n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|          ( o.o )      |  |                                      (='.'=)            |\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|           > ^ <       |  |   PROGRAMMING LANGUAGE (0__0)       (\'\')_(\'\')   ☆       |\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t| ☆                     |  |____                                                     |\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|                       |_______|                         ☆                          |\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|                                                                                    |\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|         ☆          ☆     知識が増えます || 私はパワーを得る                    ☆   |\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|                  ____          ____    ____  ___   __ __   ___          ☆          |\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|      ☆          |    | |   | |  __/   | __  | _ | |  |  | |_                   ☆   |\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|                 |__ \\| |___| | /___   |___| |   | |     | |___    ☆                | \n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|                                                                                    |\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|          (づ ᴗ _ᴗ)づ♡| Rustico Eric E. Talaugon III - BSCPE-1|(˶˃ ᵕ ˂˶)   ☆        |\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|      ☆                                                                             |\n");fflush(stdout);usleep(100000);
    printf("\t\t\t\t|____________________________________________________________________________________|\n");fflush(stdout);usleep(100000);
}
void loading_screen4() 
{
   printf("\t\t\t\t ____________________________________________________________________________________\n");
    printf("\t\t\t\t|                        _______                                                     |\n");
    printf("\t\t\t\t|    ☆     (\\___/)      |  _____|                                  /\\_/\\    ☆        |   \n");
    printf("\t\t\t\t|          ( o.o )      |  |                                      (='.'=)            |\n");
    printf("\t\t\t\t|           > ^ <       |  |   PROGRAMMING LANGUAGE (0__0)       (\'\')_(\'\')   ☆       |\n");
    printf("\t\t\t\t| ☆                     |  |____                                                     |\n");
    printf("\t\t\t\t|                       |_______|                         ☆                          |\n");
    printf("\t\t\t\t|                                                                                    |\n");
    printf("\t\t\t\t|         ☆          ☆     知識が増えます || 私はパワーを得る                    ☆   |\n");
    printf("\t\t\t\t|                  ____          ____    ____  ___   __ __   ___          ☆          |\n");
    printf("\t\t\t\t|      ☆          |    | |   | |  __/   | __  | _ | |  |  | |_                   ☆   |\n");
    printf("\t\t\t\t|                 |__ \\| |___| | /___   |___| |   | |     | |___    ☆                | \n");
    printf("\t\t\t\t|                                                                                    |\n");
    printf("\t\t\t\t|          (づ ᴗ _ᴗ)づ♡| Rustico Eric E. Talaugon III - BSCPE-1|(˶˃ ᵕ ˂˶)   ☆        |\n");
    printf("\t\t\t\t|      ☆                                                                             |\n");
    printf("\t\t\t\t|____________________________________________________________________________________|\n");
}

void loading_texts(int hd) 
{
    switch (hd) 
    {
        case 1:
            printf("\n\t\t\t\t\t\t\tPreparing brain cells to function\n");
            break;
        case 2:
            printf("\n\t\t\t\t\t\t\tRandomizing or not, your fate won't change\n");
            break;
        case 3:
            printf("\n\t\t\t\t\t\tRebooting synapses for a firmware update of facts\n");
            break;
        case 4:
            printf("\n\t\t\t\t\t\tGenerating brainpower at 1000 MegaWatts per hour\n");
            break;
        case 5:
            printf("\n\t\t\t\t\t\tGobbling up SSDs to fuel the memory machine\n");
            break;
        case 6:
            printf("\n\t\t\t\t\t\tRoses are , Violet are blue, 'matic plat uno\n");
            break;
        case 7:
            printf("\n\t\t\t\t\t\tI love this course || I love this course\n");
            break;
        case 8:
            printf("\n\t\t\t\t\t\tSending A Thousand Prayer to Lord\n");
            break;
        case 9:
            printf("\n\t\t\t\t\t\t\tWho's at fault? The question or Me?\n");
            break;
        case 10:
            printf("\n\t\t\t\t\t\t\tWhy I am here in Engineering?\n");
            break;
    }
}




void easter_itlog()
{   
    int code;
    system("clear");
    printf("Wowzers");fflush(stdout);sleep(1);
    system("clear");
    printf("Bat ka sumulod dito?");fflush(stdout);sleep(1);
    system("clear");
    printf("To ");fflush(stdout);usleep(100000);
    printf("gaineth ");fflush(stdout);usleep(100000);
    printf("passage ");fflush(stdout);usleep(100000);
    printf("unto ");fflush(stdout);usleep(100000);
    printf("the ");fflush(stdout);usleep(100000);
    printf("forbidden ");fflush(stdout);usleep(100000);
    printf("chambers, ");fflush(stdout);usleep(100000);
    printf("prithee, reveal ");fflush(stdout);usleep(100000);
    printf(" reveal the ");fflush(stdout);usleep(100000);
    printf(" the mystical ");fflush(stdout);usleep(100000);
    printf("code.\n");fflush(stdout);usleep(100000);
    printf(" o\n") ; 
    printf("/|\\<------ this is the guard\n");
    printf("/ \\\n");
    printf(" ^\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf("give it to this guy\n");
    scanf("%d", &code);
    if (code == 3262005)
    {
        system("clear");
        printf("1. Easy Level focuses on History.\n");
        printf("2. Medium Level focuses on C Programming Language such as the statements and functions.\n");
        printf("3. Hard Level focuses Programming Application specifically on calculations.\n");
        printf("4. In Hard Level, most of the numbers are referenced to the birthdate of  jinsei no tokubetsu na hitobito.\n");
        printf("\t4a. 1/19 - CEO(Wowzers the abbreviations lol)\n"); 
        printf("\t4b. 1/20 - JCE\n");
        printf("\t4c. 2/17 - RB-III\n");
        printf("\t4d. 2/22 - HDC\n");
        printf("\t4e. 3/05 - MRT\n");
        printf("\t4f. 3/21 - CN\n");
        printf("\t4g. 3/26 - SHL\n");
        printf("\t4h. 4/13 - RET-III\n");
        printf("\t4i. 5/14 - AJA\n");
        printf("\t4k. 6/30 - RA-JR.\n");
        printf("\t4l. 9/27 - MRA\n");
        printf("\t4l. 10/02 - RT-JR.\n");
        printf("5.\"jinsei no tokubetsu na hitobito\" means \"special people in life\". \n");
        printf("6. Excluding the main function, there are 33 local functions in this program. \n");
        printf("\t6a. 24 of the local functions are \"no return and no parameter\" user-defined functions\n");
        printf("\t6b. 9 of the local functions are \"no return but has parameter\" user-defined functions\n");
        printf("7. There are 6 macros initialized in this program. \n");
        printf("8. In the second size of the array initialized the value \"2024\" represents the year of program's development.\n");
        printf("9. 9/27/2006 which is used as one of the references, is the birth date of someone I like. \n");
        printf("10. ILY means \"I Like You\". \"I Love You\" is locked cos No Label pa:)). \n");
        printf("11. This program contains exactly 1079 lines. \n");

        
        fflush(stdout);
        sleep(20);
        system("clear");
        printf("There is no getting out now you know the secrets:)\n");
        sleep(1);
        system("clear");
        printf("CODE:TERMINATION now initiated..\n");
        sleep(1);
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        printf("101010010100010101010101010101010101010010101010100101001010101010101010101101010101010101010\n");
        sleep(5);
        system("clear");
        printf("CODE:TERMINATION successful..");
        exit(0);
    }
    else 
    {
        system("clear");
        printf("X       X         X       X\n"); 
        printf(" X     X           X     X\n"); 
        printf("  X   X             X   X\n"); 
        printf("   X X               X X\n"); 
        printf("    X                 X\n");
        printf("   X X               X X\n");
        printf("  X   X             X   X\n");
        printf(" X     X           X     X\n");
        printf("X       X         X       X\n");
        printf("Get outta here! Stranger!");
        fflush(stdout);
        exit(0);
    }
}


void input_username_display()
{
    printf("\n\t\t\t\t\t\t\tE");fflush(stdout);usleep(100000);
    printf("n");fflush(stdout);usleep(100000); 
    printf("t");fflush(stdout);usleep(100000);
    printf("e");fflush(stdout);usleep(100000);
    printf("r ");fflush(stdout);usleep(100000);
    printf("y");fflush(stdout);usleep(100000);
    printf("o");fflush(stdout);usleep(100000); 
    printf("u");fflush(stdout);usleep(100000);
    printf("r ");fflush(stdout);usleep(100000);
    printf("n");fflush(stdout);usleep(100000);
    printf("a");fflush(stdout);usleep(100000);
    printf("m");fflush(stdout);usleep(100000);
    printf("e: ");fflush(stdout);usleep(100000);
}

void main_menu_charot_button()
{
    printf("\t\t\t\t\t\t\t _______________________________\n");
    printf("\t\t\t\t\t\t\t|                               |\n");
    printf("\t\t\t\t\t\t\t|        Enter 1 to Start       |\n");
    printf("\t\t\t\t\t\t\t|_______________________________|\n");
    printf("\t\t\t\t\t\t\t _______________________________\n");
    printf("\t\t\t\t\t\t\t|                               |\n");
    printf("\t\t\t\t\t\t\t|     Just a Normal Button :3   |\n");
    printf("\t\t\t\t\t\t\t|_______________________________|\n");
    printf("\t\t\t\t\t\t\t _______________________________\n");
    printf("\t\t\t\t\t\t\t|                               |\n");
    printf("\t\t\t\t\t\t\t|        Enter 2 to exit        |\n");
    printf("\t\t\t\t\t\t\t|_______________________________|\n");
}

void choose_diff1_txt_disp ()
{
    printf("Choo");fflush(stdout);usleep(100000);
    printf("se Di");fflush(stdout);usleep(100000);
    printf("fficu");fflush(stdout);usleep(100000);
    printf("lty.");fflush(stdout);usleep(100000);
    printf("\n 1. ");fflush(stdout);usleep(100000);
    printf("Easy \n ");fflush(stdout);usleep(100000);
    printf("2. ");fflush(stdout);usleep(100000);
    printf("Medium \n");fflush(stdout);usleep(100000);
    printf(" 3. ");fflush(stdout);usleep(100000);
    printf("Hard\n");fflush(stdout);usleep(100000);
    printf(" 4. ");fflush(stdout);usleep(100000);
    printf("Asian\n");fflush(stdout);usleep(100000);
}

void answer_txt_disp()
{
    printf("\n\nM");fflush(stdout);usleep(400000);
    printf("y A");fflush(stdout);usleep(400000);
    printf("ns");fflush(stdout);usleep(400000);
    printf("we");fflush(stdout);usleep(400000);
    printf("r\n");fflush(stdout);usleep(400000);
    printf("( ᴗ _ᴗ)づ");fflush(stdout);usleep(400000);
    printf("づ");fflush(stdout);usleep(1200000);
}

void inst_txt_disp()
{
    system("clear");
    loading_screen4();
    printf("Loading please wait....\n");
    printf("Instruction: Read each questions carefully. Multiple Choices. Please choose the correct answer. UPPERCASE/CAPITAL LETTERS ONLY");
    fflush(stdout);
    sleep(10);
}

void inst_txt_disp1()
{
    system("clear");
    loading_screen4();
    printf("Loading please wait....\n");
    printf("Instruction: Read each questions carefully. Problem-solving. Please input the correct answer. You may use scientific calculator. You really need it lol.\nNote: For scientific notation, the format must be 2.17 * 10^22");
    fflush(stdout);
    sleep(10);
}
void correct_ans()
{
    printf("Correct Answer. Proceeding to the next question.\n");
    sleep(2);
}

void incorrect_ans()
{
    printf("Incorrect Answer. Proceeding to the next question.\n");
    sleep(2);
}

void correct_ans_final()
{
    printf("Correct Answer. Calculating the score.\n");
    sleep(2);
}

void incorrect_ans_final()
{
    printf("Incorrect Answer. Calculating the score.\n");
    sleep(2);
}

void game_opt()
{
    printf("Enter 0 to restart the program\n");
    printf("Enter 1 to exit the program\n\n\n");
}

void game_restart()
{
    int diff1=0;
    system("clear");
    loading_screen4();
    choose_diff1();
}

void play_again()
{
    char pa = '\0';
    printf("Play Again[Y/N]: ");
    scanf(" %c", &pa); 
    if (pa == 'Y' || pa == 'y') 
    {
        game_restart();
    }
    else if (pa == 'N' || pa == 'n') 
    {
        system("clear");
        exit_prog();
        exit(0);
    }
}

void exit_prog()
{
    printf("\t\t\t\t ____________________________________________________________________________________\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                                                                                    |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|       _____________                                                                |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|            |             |                 \\           /                           |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|            |             |                  \\         /                            |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|            |             |                   \\       /                             |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|            |             |                    \\     /        /\\     /\\             |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|            |             |                     \\   /        /  \\   /  \\            |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|            |             |                      \\ /                                |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|            |             |                       |                                 |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|            |             |                       |            _______              |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|            |             |                       |                                 |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|            |             |                       |                                 |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|       _____|_______      |_______________        |                                 |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|                                            5-9-27-4-13-7                           |\n");fflush(stdout);usleep(10000);
    printf("\t\t\t\t|____________________________________________________________________________________|\n");fflush(stdout);usleep(10000);
}

void shuffle_array(char arr[][2024], char choices[][2024], char answers[][2024],int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap questions
        char temp[2024];
        strcpy(temp, arr[i]);
        strcpy(arr[i], arr[j]);
        strcpy(arr[j], temp);
        // Swap choices
        strcpy(temp, choices[i]);
        strcpy(choices[i], choices[j]);
        strcpy(choices[j], temp);
        
        strcpy(temp, answers[i]);
        strcpy(answers[i], answers[j]);
        strcpy(answers[j], temp);
    }
}














