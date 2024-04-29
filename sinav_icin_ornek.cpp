#include "stdio.h"
#include "conio.h"
#include "string.h"
#include <stdlib.h>

void TusaBas(int tus_sayisi); // fonksiyonların tanımlanması
void Ucgenler();
void firstU(int satir);
void secondU(int satir);
void thirdU(int satir);
void fourthU(int satir);
int satirSayisi();
int elemanSayisi();

int k = 9, s = 1; // aşağıda fonksiyonlarda genel olarak kullanıldıkları için buraya yazıldı

void main()
{
    char User_check1[6], User_check2[10];                                                               // kullanıcı isimlerinin oluşturulması
    char User1_pswrd[5], User2_pswrd[5];                                                                // şifrelerin oluşturulması
    int isUser = 1, is_pswrd = 1, ucgen, fib1 = 1, fib2 = 1, fibn, wrng_ucgn = 1, range, fib_cntrl = 1; // koddda kullanılan verilerin tanımlanması

    strcpy(User_check1, "ucgen");     // kullanıcılara isim şifreye sayıların atanması
    strcpy(User_check2, "fibonacci"); // strcpy()  "string.h" kütüphanesinin bir fonksiyonudur
    strcpy(User1_pswrd, "1234");
    strcpy(User2_pswrd, "9876");

    char User[10], password[5], yildiz = '*';
    ; // kullanıcının girmesi için oluşturukan char lar

    do
    {
        printf("Kullanici adinizi giriniz: ");
        scanf_s("%s", User, sizeof(User));                                    // kullanıcı isminin User değişkenine atanması
        if (strcmp(User, User_check1) == 0 || strcmp(User, User_check2) == 0) // Kullanıcı ismi hazır bulunan isimlerle uyuşuyor mu kontrolünün sağlanması
            isUser = 1;
        else
        {
            isUser = 0; // eğer kullanıcı isimleri uyuşmuyorsa do while döngüsü ile tekrar başa dönmek için kontrol değişkenine değişiklik yapılması
            printf("Kullanici bulunamadi tekrar deneyin.\n");
        }

    } while (isUser == 0); // eğer kullanıcı ismi hatalı girildiyse döngü baştan alınır

    do
    {
        int i = 0;
        printf("Sifrenizi giriniz: ");
        while (i < 4)
        {
            password[i] = _getch();

            if (password[i] == 8)
            {
                i--;
                printf("\b \b", i);
            }
            else if (password[i] >= 48 && password[i] <= 57)
            {
                _putch(yildiz);
                i++;
            }
        }

        password[4] = '\0'; // kullanıcının şifreyi girmesi ve password değişkenine atanması

        if (strcmp(password, User1_pswrd) == 0 && strcmp(User, User_check1) == 0 || strcmp(password, User2_pswrd) == 0 && strcmp(User, User_check2) == 0)
            is_pswrd = 1; // buradaki if kısmında kullanıcıyla beraber şifre uyuşuyorsa kontrol değişkenine 1 (DOĞRU) atanır
        else
        {
            is_pswrd = 0; // şifre yanlışsa kontrol değişkenine 0 (YANLIŞ) atanır
            printf("\nSifre yanlis tekrar deneyin.\n");
        }
    } while (is_pswrd == 0); // kontrol değişkeni (yani kullanıcının girdği şifre) yanlışsa döngü baştan başlar

    if (strcmp(User, User_check1) == 0) // eğer kullanıcı "ucgen" kullanıcı adı ile giriş yaptıysa program buradan devam eder "fibonacci" ile giriş yaptıysa 85. satırdan devam eder"
    {
        printf("\n1.    2.    3.    4.\n");
        Ucgenler(); // 137. satırda başlayan Ucgenler() fonksiyonu çalıştırılır
        printf("buyuk olcekte yazdirmak istediginiz ucgeni secin: ");
        do
        {
            scanf_s("%d", &ucgen); // yazdırmak istediğimiz üçgen seçilir
            switch (ucgen)         // switch fonksiyonu ile yazdırılmak istenen üçgen yazdırılır
            {
            case 1:
                firstU(satirSayisi());
                wrng_ucgn = 1;
                break;
            case 2:
                secondU(satirSayisi());
                wrng_ucgn = 1;
                break;
            case 3:
                thirdU(satirSayisi());
                wrng_ucgn = 1;
                break;
            case 4:
                fourthU(satirSayisi());
                wrng_ucgn = 1;
                break;
            default:
                printf("Yanlis numara girdiniz tekrar deneyin: "); // yazdırılmak istenen ucgen değeri 1-4 aralığında değilse tekrar do while döngüsyle giriş sağlanır
                wrng_ucgn = 0;
                break;
            }
            printf("\a"); // sistem uyarı sesi çıkar
        } while (wrng_ucgn == 0);
    }
    else
    {
        printf("\n %d, %d", fib1, fib2); // fibonacci dizisinin örnek amaçlı ilk 10 elemanı yazdırılır
        for (size_t i = 1; i <= 8; i++)
        {
            fibn = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibn;
            printf(", %d", fibn);
        }
        printf("\nFibonacci dizisi olusturmak isteginiz iki tam sayiyi giriniz: "); // diziyi başlatmak istediğimiz ilk 2 değer aralarında bir boşluk olacak şekilde girilir
        do
        {
            scanf_s("%d %d", &fib1, &fib2); // dizinin ilk iki elemanı alınır

            if (fib1 >= fib2 || fib1 < 0) // ilk eleman ikinci elemandan küçük mü diye kontrol edilir
            {
                printf("Ilk sayinizi kucuk giriniz:");
                fib_cntrl = 0;
            }
            else
                fib_cntrl = 1;
        } while (fib_cntrl == 0);

        printf("Fibonacci dizisinde kac tane eleman olmasini istersiniz: "); // dizide kaç eleman olması istendiği yazılır
        range = elemanSayisi();

        printf("%d, %d", fib1, fib2);
        for (size_t i = 1; i <= range - 2; i++) // istenilen sayıda eleman ekrana yazdırılır
        {
            fibn = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibn;
            printf(", %d", fibn);
        }
        printf("\n \a"); // sistem uyarı sesi çıkar
    }

    TusaBas(2); // eğer kodda birden fazla scanf_s var ise 2 veya daha büyük bir sayı yazılır
}

void TusaBas(int tus_sayisi)
{
    if (tus_sayisi > 1)
    {
        getchar();
        getchar();
    }
    else
        getchar();
}

void Ucgenler() // ekrana sırasıyla 4 tane üçgen yapar
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        for (int l = 1; l <= k; l++)
        {
            printf(" ");
        }
        k -= 2;
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf(" ");

        for (int j = 1; j <= 6 - i; j++)
        {
            printf("*");
        }
        for (int l = 1; l <= s; l++)
        {
            printf(" ");
        }
        s += 2;
        for (int j = 1; j <= 6 - i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void firstU(int satir) // büyük üçgenleri yapan fonksiyonlar
{
    for (int i = 1; i <= satir; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void secondU(int satir)
{
    for (int i = satir; i > 0; i--)
    {
        for (int k = 1; k < i + 2 - 1; k++)
        {
            printf(" ");
        }
        for (int j = 1; j <= satir + 1 - i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}
void thirdU(int satir)
{
    for (int i = satir; i >= 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void fourthU(int satir)
{
    for (int i = satir; i > 0; i--)
    {
        for (int j = satir; j > i; j--)
        {
            printf(" ");
        }
        for (int l = 1; l <= i; l++)
        {
            printf("*");
        }
        printf("\n");
    }
}
int satirSayisi()
{
    int str, check;
    char a[20];

    printf("Kac satir yazdirmak istiyorsunuz: ");
    do
    {
        scanf_s("%s", a, sizeof(a));
        str = atoi(a);
        if (str < 1)
        {
            printf("Degeri 1 den buyuk girin: ");
            check = 0;
        }
        else
            check = 1;

    } while (check == 0);
    return str;
}

int elemanSayisi()
{
    int range, chck;
    char a[20];

    do
    {
        scanf_s("%s", a, sizeof(a));
        range = atoi(a);
        if (range < 1 || range > 100)
        {
            printf("Lutfen eleman sayisini 1 - 100 araliginda giriniz: ");
            chck = 0;
        }
        else
            chck = 1;

    } while (chck == 0);
    return range;
}
