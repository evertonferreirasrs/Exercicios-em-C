#include <allegro5/allegro.h>     // www.github.com / rafaeltoledo/curso-allegro
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool audio = true;
int contmusica = 2;
int personagem;
int cont;

void monta_menu_avatar(int opcao_selecionada)
{

    ALLEGRO_BITMAP *homem1 = al_load_bitmap("Recursos/Opcoes/personagem/homem1.jpg");
    ALLEGRO_BITMAP *homem2 = al_load_bitmap("Recursos/Opcoes/personagem/homem2.jpg");
    ALLEGRO_BITMAP *mulher1 = al_load_bitmap("Recursos/Opcoes/personagem/mulher1.jpg");
    ALLEGRO_BITMAP *mulher2 = al_load_bitmap("Recursos/Opcoes/personagem/mulher2.jpg");

    //Primeiro botao
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(homem2, 250 , 300, 0);
    }
    else
    {
        al_draw_bitmap(homem1, 250, 300, 0);

    }
    // Segundo botao
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(mulher2, 550, 300, 0);
    }
    else
    {
        al_draw_bitmap(mulher1, 550, 300, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (homem1);
    al_destroy_bitmap (homem2);
    al_destroy_bitmap (mulher1);
    al_destroy_bitmap (mulher2);

}

void mostra_escolha_avatar()
{
    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;

    //ALLEGRO_FONT *fonte = al_load_font("ace_gaffigan.ttf", 48, 0);

    // Declara a imagem de fundo
    ALLEGRO_BITMAP *FundoEscolhaPersonagem;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    FundoEscolhaPersonagem = al_load_bitmap("Recursos/Opcoes/FundoEscolhaPersonagem.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(FundoEscolhaPersonagem, 0, 0, 0);
    // Aplica as alterações na
    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool entrar = false;
    while (entrar == false)
    {
        al_draw_bitmap(FundoEscolhaPersonagem, 0, 0, 0);


        monta_menu_avatar(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                entrar = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {

                if (evento.keyboard.keycode ==
                        ALLEGRO_KEY_ENTER)
                {
                    entrar = true;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT)
                {
                    opcao_menu++;
                    if (opcao_menu > 2)
                    {
                        opcao_menu = 1;
                        personagem = 0;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu = 2;
                        personagem = 1;
                    }
                }
            }


        }
    }

// Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(FundoEscolhaPersonagem);

    return 0;
}

void mostra_jogo0()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo0;

    double tempo_inicial, tempo_final;
    bool sair = false;

    fundo0 = al_load_bitmap("Recursos/fundo0.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundo0, 0, 0, 0);

    while (sair == false)
    {
        tempo_inicial = al_get_time();

        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_eventos, &evento);

        al_flip_display();

        bool tecla;

        if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            tecla = true;
        }
        else if (evento.type == ALLEGRO_EVENT_KEY_UP)
        {
            tecla = false;
        }
        if (tecla == true)
        {
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
            {
                sair = true;
            }
        }
    }

    al_destroy_bitmap (fundo0);
}
//mostra a primeira tela de jogo
void mostra_jogo()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo2;// Declara a imagem de fundo

    ALLEGRO_BITMAP *persone;
    ALLEGRO_BITMAP *persond;
    ALLEGRO_BITMAP *personc;
    ALLEGRO_BITMAP *personf;

    if (personagem == 0)
    {
        persone = al_load_bitmap("Recursos/meninoe.png");
        persond = al_load_bitmap("Recursos/meninod.png");
        personc = al_load_bitmap("Recursos/meninoc.png");
        personf = al_load_bitmap("Recursos/meninof.png");
    }
    else
    {
        persone = al_load_bitmap("Recursos/meninae.png");
        persond = al_load_bitmap("Recursos/meninad.png");
        personc = al_load_bitmap("Recursos/meninac.png");
        personf = al_load_bitmap("Recursos/meninaf.png");
    }
    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;
    int x = 500;
    int y = 650;

    fundo2 = al_load_bitmap("Recursos/fundo2.jpg");

    al_draw_bitmap(fundo2, 0, 0, 0);

    while (sair == false)
    {
        tempo_inicial = al_get_time();

        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_eventos, &evento);

        if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT)
        {
            al_draw_bitmap(persond, x , y, 0);
        }
        else if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT)
        {
            al_draw_bitmap(persone, x, y, 0);

        }
        else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            al_draw_bitmap(personf, x, y, 0);

        }
        else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
        {
            al_draw_bitmap(personc, x, y, 0);

        }


        // Aplica as alterações na tela
        al_flip_display();


        // declaracao variavel boneco
        bool tecla;

        if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            tecla = true;
        }
        else if (evento.type == ALLEGRO_EVENT_KEY_UP)
        {
            tecla = false;
        }
        if (tecla == true)
        {
            mostra_escolha_avatar;
            if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                sair = true;
            }

            else if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                ALLEGRO_BITMAP *fundo2 = al_load_bitmap("Recursos/fundo2.jpg");


                al_draw_bitmap(fundo2, 0, 0, 0);
                x += 15;
                if (x > 535)
                {
                    x-=15;
                }
                al_draw_bitmap(persond, x,  y, 0);


                al_flip_display();


                al_destroy_bitmap (fundo2);

            }
            else if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                ALLEGRO_BITMAP *fundo2 = al_load_bitmap("Recursos/fundo2.jpg");

                al_draw_bitmap(fundo2, 0, 0, 0);
                x -= 15;
                if (x < 445)

                {
                    x+=15;
                }

                al_draw_bitmap(persone, x, y, 0);

                al_flip_display();


                al_destroy_bitmap (fundo2);

            }
            else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
            {
                ALLEGRO_BITMAP *fundo2 = al_load_bitmap("Recursos/fundo2.jpg");


                al_draw_bitmap(fundo2, 0, 0, 0);
                y += 15;
                if (y > 665)
                {
                    y-=15;
                }
                al_draw_bitmap(personf, x, y, 0);

                al_flip_display();


                al_destroy_bitmap (fundo2);


            }
            else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
            {
                ALLEGRO_BITMAP *fundo2 = al_load_bitmap("Recursos/fundo2.jpg");


                al_draw_bitmap(fundo2, 0, 0, 0);
                y -= 15;

                if (y < 220)
                {
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    mostra_jogo_salas();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }
                al_draw_bitmap(fundo2, 0, 0, 0);
                al_draw_bitmap(personc, x, y, 0);

                al_flip_display();


                al_destroy_bitmap (fundo2);

            }
        }

    }
    al_destroy_bitmap (fundo2);
}
void mostra_jogo_salas()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo;// Declara a imagem de fundo

    ALLEGRO_BITMAP *persone;
    ALLEGRO_BITMAP *persond;
    ALLEGRO_BITMAP *personc;
    ALLEGRO_BITMAP *personf;

    if (personagem == 0)
    {
        persone = al_load_bitmap("Recursos/meninoe.png");
        persond = al_load_bitmap("Recursos/meninod.png");
        personc = al_load_bitmap("Recursos/meninoc.png");
        personf = al_load_bitmap("Recursos/meninof.png");
    }
    else
    {
        persone = al_load_bitmap("Recursos/meninae.png");
        persond = al_load_bitmap("Recursos/meninad.png");
        personc = al_load_bitmap("Recursos/meninac.png");
        personf = al_load_bitmap("Recursos/meninaf.png");
    }
    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;
    int x = 980;
    int y = 350;

    fundo = al_load_bitmap("Recursos/fundo3.jpg");

    al_draw_bitmap(fundo, 0, 0, 0);

    while (sair == false)
    {
        tempo_inicial = al_get_time();

        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_eventos, &evento);

        if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT)
        {
            al_draw_bitmap(persond, x , y, 0);
        }
        else if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT)
        {
            al_draw_bitmap(persone, x, y, 0);

        }
        else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            al_draw_bitmap(personf, x, y, 0);

        }
        else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
        {
            al_draw_bitmap(personc, x, y, 0);

        }

        al_flip_display();


        bool tecla;

        if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            tecla = true;
        }
        else if (evento.type == ALLEGRO_EVENT_KEY_UP)
        {
            tecla = false;
        }
        if (tecla == true)
        {
            if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                sair = true;
            }

            else if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                ALLEGRO_BITMAP *fundo = al_load_bitmap("Recursos/fundo3.jpg");

                al_draw_bitmap(fundo, 0, 0, 0);
                x += 15;
                if (x > 990)
                {
                    sair = true;
                }
                al_draw_bitmap(persond, x,  y, 0);


                al_flip_display();

                al_destroy_bitmap (fundo);

            }
            else if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                ALLEGRO_BITMAP *fundo = al_load_bitmap("Recursos/fundo3.jpg");


                al_draw_bitmap(fundo, 0, 0, 0);
                x -= 15;
                if (x < 10)

                {
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    mostra_jogo_biblioteca();
                    al_draw_bitmap(fundo, 0, 0, 0);
                    al_flip_display();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }

                al_draw_bitmap(persone, x, y, 0);

                al_flip_display();

                al_destroy_bitmap (fundo);

            }
            else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
            {
                ALLEGRO_BITMAP *fundo = al_load_bitmap("Recursos/fundo3.jpg");


                al_draw_bitmap(fundo, 0, 0, 0);
                y += 15;

                if (x > 0 && x < 40 && y > 440)//entrada judo
                {
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    monta_judop1();
                    monta_judop2();
                    monta_judop3();
                    monta_judop4();
                    monta_judop5();
                    monta_judop6();
                    monta_judop7();
                    monta_judop8();
                    monta_judop9();
                    monta_judop10();
                    resultado();
                    al_draw_bitmap(fundo, 0, 0, 0);
                    al_flip_display();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }
                if (x > 41 && x < 187 && y > 400)//parede judo
                {
                    y=400;
                }
                if (x > 188 && x < 238 && y > 440)//entrada atletismo
                {
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    monta_atletismop1();
                    monta_atletismop2();
                    monta_atletismop3();
                    monta_atletismop4();
                    monta_atletismop5();
                    monta_atletismop6();
                    monta_atletismop7();
                    monta_atletismop8();
                    monta_atletismop9();
                    monta_atletismop10();
                    resultado();
                    al_draw_bitmap(fundo, 0, 0, 0);
                    al_flip_display();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }
                if (x > 239 && x < 411 && y > 400)//parede atletismo
                {
                    y=400;
                }
                if (x > 412 && x < 442 && y > 440)//entrada basquete
                {
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    monta_basquetep1();
                    monta_basquetep2();
                    monta_basquetep3();
                    monta_basquetep4();
                    monta_basquetep5();
                    monta_basquetep6();
                    monta_basquetep7();
                    monta_basquetep8();
                    monta_basquetep9();
                    monta_basquetep10();
                    resultado();
                    al_draw_bitmap(fundo, 0, 0, 0);
                    al_flip_display();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }
                if (x > 443 && x < 619 && y > 400)//parede basquete
                {
                    y=400;
                }
                if (x > 619 && x < 639 && y > 440)//entrada tenis
                {
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    monta_tenisp1();
                    monta_tenisp2();
                    monta_tenisp3();
                    monta_tenisp4();
                    monta_tenisp5();
                    monta_tenisp6();
                    monta_tenisp7();
                    monta_tenisp8();
                    monta_tenisp9();
                    monta_tenisp10();
                    resultado();
                    al_draw_bitmap(fundo, 0, 0, 0);
                    al_flip_display();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }
                if (x > 640 && x < 824 && y > 400)//parede tenis
                {
                    y=400;
                }
                if (x > 825 && x < 855 && y > 440)//entrada futsal
                {
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    monta_futsalp1();
                    monta_futsalp2();
                    monta_futsalp3();
                    monta_futsalp4();
                    monta_futsalp5();
                    monta_futsalp6();
                    monta_futsalp7();
                    monta_futsalp8();
                    monta_futsalp9();
                    monta_futsalp10();
                    resultado();
                    al_draw_bitmap(fundo, 0, 0, 0);
                    al_flip_display();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }
                if (x > 856 && x < 1000 && y > 400)//parede futsal
                {
                    y=400;
                }
                al_draw_bitmap(personf, x, y, 0);

                al_flip_display();

                al_destroy_bitmap (fundo);
            }
            else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
            {
                ALLEGRO_BITMAP *fundo = al_load_bitmap("Recursos/fundo3.jpg");


                al_draw_bitmap(fundo, 0, 0, 0);
                y -= 15;
                if (y < 10)
                {
                    y+=15;
                }

                if (x > 0 && x < 40 && y < 200)//entrada natação
                {
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    monta_natacaop1();
                    monta_natacaop2();
                    monta_natacaop3();
                    monta_natacaop4();
                    monta_natacaop5();
                    monta_natacaop6();
                    monta_natacaop7();
                    monta_natacaop8();
                    monta_natacaop9();
                    monta_natacaop10();
                    resultado();
                    al_draw_bitmap(fundo, 0, 0, 0);
                    al_flip_display();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }
                if (x > 41 && x < 187 && y < 240)//parede natação
                {
                    y=240;
                }
                if (x > 188 && x < 238 && y < 200)//entrada ginastica
                {
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    monta_ginasticap1();
                    monta_ginasticap2();
                    monta_ginasticap3();
                    monta_ginasticap4();
                    monta_ginasticap5();
                    monta_ginasticap6();
                    monta_ginasticap7();
                    monta_ginasticap8();
                    monta_ginasticap9();
                    monta_ginasticap10();
                    resultado();
                    al_draw_bitmap(fundo, 0, 0, 0);
                    al_flip_display();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }
                if (x > 239 && x < 411 && y < 240)//parede ginastica
                {
                    y=240;
                }
                if (x > 412 && x < 442 && y < 200)//entrada volei
                {
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    monta_voleip1();
                    monta_voleip2();
                    monta_voleip3();
                    monta_voleip4();
                    monta_voleip5();
                    monta_voleip6();
                    monta_voleip7();
                    monta_voleip8();
                    monta_voleip9();
                    monta_voleip10();
                    resultado();
                    al_draw_bitmap(fundo, 0, 0, 0);
                    al_flip_display();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }
                if (x > 443 && x < 619 && y < 240)//parede volei
                {
                    y=240;
                }
                if (x > 619 && x < 639 && y < 200)//entrada handebol
                {
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    monta_handebolp1();
                    monta_handebolp2();
                    monta_handebolp3();
                    monta_handebolp4();
                    monta_handebolp5();
                    monta_handebolp6();
                    monta_handebolp7();
                    monta_handebolp8();
                    monta_handebolp9();
                    monta_handebolp10();
                    resultado();
                    al_draw_bitmap(fundo, 0, 0, 0);
                    al_flip_display();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }
                if (x > 640 && x < 824 && y < 240)//parede handebol
                {
                    y=240;
                }
                if (x > 825 && x < 855 && y < 200)//entrada futebol
                {
                    /*
                    MOSTRA PERGUNTAS



                    */

                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    monta_futp1();
                    monta_futp2();
                    monta_futp3();
                    monta_futp4();
                    monta_futp5();
                    monta_futp6();
                    monta_futp7();
                    monta_futp8();
                    monta_futp9();
                    monta_futp10();
                    resultado();
                    al_draw_bitmap(fundo, 0, 0, 0);
                    al_flip_display();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }
                if (x > 856 && x < 1000 && y < 240)//parede futebol
                {
                    y=240;
                }

                al_draw_bitmap(personc, x, y, 0);

                al_flip_display();

                al_destroy_bitmap (fundo);

            }
        }
    }
    al_destroy_bitmap (fundo);
}
//Mostra biblioteca
void mostra_jogo_biblioteca()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo;// Declara a imagem de fundo

    ALLEGRO_BITMAP *persone;
    ALLEGRO_BITMAP *persond;
    ALLEGRO_BITMAP *personc;
    ALLEGRO_BITMAP *personf;

    if (personagem == 0)
    {
        persone = al_load_bitmap("Recursos/meninoe.png");
        persond = al_load_bitmap("Recursos/meninod.png");
        personc = al_load_bitmap("Recursos/meninoc.png");
        personf = al_load_bitmap("Recursos/meninof.png");
    }
    else
    {
        persone = al_load_bitmap("Recursos/meninae.png");
        persond = al_load_bitmap("Recursos/meninad.png");
        personc = al_load_bitmap("Recursos/meninac.png");
        personf = al_load_bitmap("Recursos/meninaf.png");
    }
    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;
    int x = 450;
    int y = 650;

    fundo = al_load_bitmap("Recursos/biblioteca.jpg");

    al_draw_bitmap(fundo, 0, 0, 0);

    while (sair == false)
    {
        tempo_inicial = al_get_time();

        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_eventos, &evento);

        if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT)
        {
            al_draw_bitmap(persond, x , y, 0);
        }
        else if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT)
        {
            al_draw_bitmap(persone, x, y, 0);

        }
        else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
        {
            al_draw_bitmap(personf, x, y, 0);

        }
        else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
        {
            al_draw_bitmap(personc, x, y, 0);

        }

        al_flip_display();


        bool tecla;

        if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            tecla = true;
        }
        else if (evento.type == ALLEGRO_EVENT_KEY_UP)
        {
            tecla = false;
        }
        if (tecla == true)
        {
            if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                sair = true;
            }
            else if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                ALLEGRO_BITMAP *fundo = al_load_bitmap("Recursos/biblioteca.jpg");


                al_draw_bitmap(fundo, 0, 0, 0);
                x += 15;
                if (x > 510)
                {
                    x-=15;
                }
                al_draw_bitmap(persond, x,  y, 0);


                al_flip_display();


                al_destroy_bitmap (fundo);

            }
            else if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                ALLEGRO_BITMAP *fundo = al_load_bitmap("Recursos/biblioteca.jpg");


                al_draw_bitmap(fundo, 0, 0, 0);
                x -= 15;
                if (x < 405)

                {
                    x+=15;
                }

                al_draw_bitmap(persone, x, y, 0);

                al_flip_display();

                al_destroy_bitmap (fundo);

            }
            else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
            {
                ALLEGRO_BITMAP *fundo = al_load_bitmap("Recursos/biblioteca.jpg");


                al_draw_bitmap(fundo, 0, 0, 0);
                y += 15;
                if (y > 665)
                {
                    sair = true;
                }
                al_draw_bitmap(personf, x, y, 0);

                al_flip_display();


                al_destroy_bitmap (fundo);


            }
            else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
            {
                ALLEGRO_BITMAP *fundo = al_load_bitmap("Recursos/biblioteca.jpg");



                al_draw_bitmap(fundo, 0, 0, 0);
                y -=15;

                if (y < 225)
                {
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    regras_biblioteca();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                }
                al_draw_bitmap(fundo, 0, 0, 0);
                al_draw_bitmap(personc, x, y, 0);

                al_flip_display();


                al_destroy_bitmap (fundo);
            }
        }
    }
    al_destroy_bitmap (fundo);
}

void resultado()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo0;// Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo2;// Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo3;// Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo4;// Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo5;// Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo6;// Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo7;// Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo8;// Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo9;// Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo10;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();
        if (cont == 0)
        {
            fundo0 = al_load_bitmap("Recursos/Esportes/result0.jpg");
            // Desenhar a imagem na tela
            al_draw_bitmap(fundo0, 0, 0, 0);

            // Aplica as alterações na tela
            al_flip_display();

            al_destroy_bitmap (fundo0);
        }
        else if (cont == 1)
        {
            fundo1 = al_load_bitmap("Recursos/Esportes/result1.jpg");
            // Desenhar a imagem na tela
            al_draw_bitmap(fundo1, 0, 0, 0);

            // Aplica as alterações na tela
            al_flip_display();

            al_destroy_bitmap (fundo1);
        }
        else if (cont == 2)
        {
            fundo2 = al_load_bitmap("Recursos/Esportes/result2.jpg");
            // Desenhar a imagem na tela
            al_draw_bitmap(fundo2, 0, 0, 0);

            // Aplica as alterações na tela
            al_flip_display();

            al_destroy_bitmap (fundo2);
        }
        else if (cont == 3)
        {
            fundo3 = al_load_bitmap("Recursos/Esportes/result3.jpg");
            // Desenhar a imagem na tela
            al_draw_bitmap(fundo3, 0, 0, 0);

            // Aplica as alterações na tela
            al_flip_display();

            al_destroy_bitmap (fundo3);
        }
        else if (cont == 4)
        {
            fundo4 = al_load_bitmap("Recursos/Esportes/result4.jpg");
            // Desenhar a imagem na tela
            al_draw_bitmap(fundo4, 0, 0, 0);

            // Aplica as alterações na tela
            al_flip_display();

            al_destroy_bitmap (fundo4);
        }
        else if (cont == 5)
        {
            fundo5 = al_load_bitmap("Recursos/Esportes/result5.jpg");
            // Desenhar a imagem na tela
            al_draw_bitmap(fundo5, 0, 0, 0);

            // Aplica as alterações na tela
            al_flip_display();

            al_destroy_bitmap (fundo5);
        }
        else if (cont == 6)
        {
            fundo6 = al_load_bitmap("Recursos/Esportes/result6.jpg");
            // Desenhar a imagem na tela
            al_draw_bitmap(fundo6, 0, 0, 0);

            // Aplica as alterações na tela
            al_flip_display();

            al_destroy_bitmap (fundo6);
        }
        else if (cont == 7)
        {
            fundo7 = al_load_bitmap("Recursos/Esportes/result7.jpg");
            // Desenhar a imagem na tela
            al_draw_bitmap(fundo7, 0, 0, 0);

            // Aplica as alterações na tela
            al_flip_display();

            al_destroy_bitmap (fundo7);
        }
        else if (cont == 8)
        {
            fundo8 = al_load_bitmap("Recursos/Esportes/result8.jpg");
            // Desenhar a imagem na tela
            al_draw_bitmap(fundo8, 0, 0, 0);

            // Aplica as alterações na tela
            al_flip_display();

            al_destroy_bitmap (fundo8);
        }
        else if (cont == 9)
        {
            fundo9 = al_load_bitmap("Recursos/Esportes/result9.jpg");
            // Desenhar a imagem na tela
            al_draw_bitmap(fundo9, 0, 0, 0);

            // Aplica as alterações na tela
            al_flip_display();

            al_destroy_bitmap (fundo9);
        }
        else if (cont == 10)
        {
            fundo10 = al_load_bitmap("Recursos/Esportes/result10.jpg");
            // Desenhar a imagem na tela
            al_draw_bitmap(fundo10, 0, 0, 0);

            // Aplica as alterações na tela
            al_flip_display();

            al_destroy_bitmap (fundo10);
        }

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}

void mostra_certo()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo = al_load_bitmap("Recursos/fundocerto.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_errado()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo = al_load_bitmap("Recursos/fundoerrado.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}

//mostra o tutorial de como aprender a jogar
void mostra_tutorial1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo2;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo2 = al_load_bitmap("Recursos/fundoinstrucao1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo2, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo2);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_tutorial2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo2;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo2 = al_load_bitmap("Recursos/fundoinstrucao2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo2, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo2);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_agua1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Agua/pag1.png");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_agua2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Agua/pag2.png");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_agua3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Agua/pag3.png");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_agua4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Agua/pag4.png");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_agua5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Agua/pag5.png");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_agua6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Agua/pag6.png");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_calcio1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Calcio/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_calcio2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Calcio/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_redp1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/ReducaoPeso/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_redp2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/ReducaoPeso/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_redp3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/ReducaoPeso/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_redp4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/ReducaoPeso/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_redp5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/ReducaoPeso/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_redp6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/ReducaoPeso/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_gordura1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Gordura/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_gordura2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Gordura/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_gordura3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Gordura/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_gordura4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Gordura/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);
        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_gordura5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Gordura/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_calorias1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Calorias/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_calorias2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Calorias/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_calorias3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Calorias/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_calorias4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Calorias/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_boaa1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/BoaAlimentacao/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_boaa2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/BoaAlimentacao/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_boaa3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/BoaAlimentacao/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);
        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_boaa4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/BoaAlimentacao/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_boaa5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/BoaAlimentacao/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_proteina1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Proteinas/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_proteina2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Proteinas/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_proteina3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Proteinas/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_proteina4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Proteinas/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_proteina5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Proteinas/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_proteina6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Proteinas/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_qualidadea1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/QualidadeAlimento/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_qualidadea2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/QualidadeAlimento/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_qualidadea3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/QualidadeAlimento/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_carboidrato1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Carboidrato/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_carboidrato2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Carboidrato/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_carboidrato3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/Carboidrato/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_atf1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/AtividadeFisica/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_atf2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/AtividadeFisica/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_atf3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/AtividadeFisica/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_atf4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/AtividadeFisica/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_nut_atf5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/nutricao/Temas/AtividadeFisica/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);
        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas7()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag7.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas8()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag8.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas9()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag9.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas10()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag10.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas11()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag11.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas12()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag12.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);
        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas13()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag13.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas14()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag14.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas15()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag15.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas16()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag16.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas17()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag17.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas18()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag18.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_drogas19()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Drogas/pag19.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_anabolizantes1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Anabolizantes/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_anabolizantes2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Anabolizantes/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_anabolizantes3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Anabolizantes/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_anabolizantes4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Anabolizantes/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_anabolizantes5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Anabolizantes/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_anabolizantes6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Anabolizantes/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_anabolizantes7()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Anabolizantes/pag7.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_anabolizantes8()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Anabolizantes/pag8.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_anabolizantes9()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Anabolizantes/pag9.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_anabolizantes10()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Anabolizantes/pag10.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_anabolizantes11()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Anabolizantes/pag11.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_anabolizantes12()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Anabolizantes/pag12.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia7()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag7.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia8()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag8.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia9()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag9.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia10()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag10.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia11()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag11.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia12()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag12.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia13()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag13.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia14()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag14.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia15()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag15.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia16()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag16.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia17()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag17.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_cur_ergonomia18()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Curiosidades/Ergonomia/pag18.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void monta_menucuriosidades(int opcao_selecionada)
{

    ALLEGRO_BITMAP *anabolizantes1 = al_load_bitmap("Recursos/curiosidades/anabolizantes1.png");
    ALLEGRO_BITMAP *anabolizantes2 = al_load_bitmap("Recursos/curiosidades/anabolizantes2.png");
    ALLEGRO_BITMAP *ergonomia1 = al_load_bitmap("Recursos/curiosidades/ergonomia1.png");
    ALLEGRO_BITMAP *ergonomia2 = al_load_bitmap("Recursos/curiosidades/ergonomia2.png");
    ALLEGRO_BITMAP *drogas1 = al_load_bitmap ("Recursos/curiosidades/drogas1.png");
    ALLEGRO_BITMAP *drogas2 = al_load_bitmap ("Recursos/curiosidades/drogas2.png");


    // Primeira opçao do menu Drogas
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(drogas2, 350 , 250, 0);
    }
    else
    {
        al_draw_bitmap(drogas1, 350, 250, 0);

    }
    // Segundo botao do menu Anabolizantes
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(anabolizantes2, 350, 350, 0);
    }
    else
    {
        al_draw_bitmap(anabolizantes1, 350, 350, 0);
    }
    // Terceiro botao no menu Drogas
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(ergonomia2, 350, 450, 0);
    }
    else
    {
        al_draw_bitmap(ergonomia1, 350, 450, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (anabolizantes1);
    al_destroy_bitmap (anabolizantes2);
    al_destroy_bitmap (drogas1);
    al_destroy_bitmap (drogas2);
    al_destroy_bitmap (ergonomia1);
    al_destroy_bitmap (ergonomia2);
}
void monta_curiosidades()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundocuriosidade;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundocuriosidade = al_load_bitmap("Recursos/Curiosidades/FundoMenuCuriosidades.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundocuriosidade, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundocuriosidade, 0, 0, 0);
        monta_menucuriosidades(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode ==
                        ALLEGRO_KEY_ESCAPE)
                {
                    sair = true;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 3)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu >3)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 3)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =3;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 4)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_cur_drogas1();
                        mostra_cur_drogas2();
                        mostra_cur_drogas3();
                        mostra_cur_drogas4();
                        mostra_cur_drogas5();
                        mostra_cur_drogas6();
                        mostra_cur_drogas7();
                        mostra_cur_drogas8();
                        mostra_cur_drogas9();
                        mostra_cur_drogas10();
                        mostra_cur_drogas11();
                        mostra_cur_drogas12();
                        mostra_cur_drogas13();
                        mostra_cur_drogas14();
                        mostra_cur_drogas15();
                        mostra_cur_drogas16();
                        mostra_cur_drogas17();
                        mostra_cur_drogas18();
                        mostra_cur_drogas19();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_cur_anabolizantes1();
                        mostra_cur_anabolizantes2();
                        mostra_cur_anabolizantes3();
                        mostra_cur_anabolizantes4();
                        mostra_cur_anabolizantes5();
                        mostra_cur_anabolizantes6();
                        mostra_cur_anabolizantes7();
                        mostra_cur_anabolizantes8();
                        mostra_cur_anabolizantes9();
                        mostra_cur_anabolizantes10();
                        mostra_cur_anabolizantes11();
                        mostra_cur_anabolizantes12();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_cur_ergonomia1();
                        mostra_cur_ergonomia2();
                        mostra_cur_ergonomia3();
                        mostra_cur_ergonomia4();
                        mostra_cur_ergonomia5();
                        mostra_cur_ergonomia6();
                        mostra_cur_ergonomia7();
                        mostra_cur_ergonomia8();
                        mostra_cur_ergonomia9();
                        mostra_cur_ergonomia10();
                        mostra_cur_ergonomia11();
                        mostra_cur_ergonomia12();
                        mostra_cur_ergonomia13();
                        mostra_cur_ergonomia14();
                        mostra_cur_ergonomia15();
                        mostra_cur_ergonomia16();
                        mostra_cur_ergonomia17();
                        mostra_cur_ergonomia18();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundocuriosidade);

    return 0;
}
void monta_menunutricao(int opcao_selecionada)
{

    ALLEGRO_BITMAP *beberagua1 = al_load_bitmap("Recursos/nutricao/BeberAgua1.png");
    ALLEGRO_BITMAP *beberagua2 = al_load_bitmap("Recursos/nutricao/BeberAgua2.png");
    ALLEGRO_BITMAP *boaa1 = al_load_bitmap("Recursos/nutricao/BoaAlimentacao1.png");
    ALLEGRO_BITMAP *boaa2 = al_load_bitmap("Recursos/nutricao/BoaAlimentacao2.png");
    ALLEGRO_BITMAP *carboidrato1 = al_load_bitmap ("Recursos/nutricao/Carboidrato1.png");
    ALLEGRO_BITMAP *carboidrato2 = al_load_bitmap ("Recursos/nutricao/Carboidrato2.png");
    ALLEGRO_BITMAP *comprarq1 = al_load_bitmap ("Recursos/nutricao/ComprarQualidade1.png");
    ALLEGRO_BITMAP *comprarq2 = al_load_bitmap ("Recursos/nutricao/ComprarQualidade2.png");
    ALLEGRO_BITMAP *cortarc1 = al_load_bitmap ("Recursos/nutricao/CortarCalorias1.png");
    ALLEGRO_BITMAP *cortarc2 = al_load_bitmap ("Recursos/nutricao/CortarCalorias2.png");
    ALLEGRO_BITMAP *exerciciof1 = al_load_bitmap("Recursos/nutricao/ExercioFisico1.png");
    ALLEGRO_BITMAP *exerciciof2 = al_load_bitmap("Recursos/nutricao/ExercioFisico2.png");
    ALLEGRO_BITMAP *gordura1 = al_load_bitmap ("Recursos/nutricao/Gordura1.png");
    ALLEGRO_BITMAP *gordura2 = al_load_bitmap ("Recursos/nutricao/Gordura2.png");
    ALLEGRO_BITMAP *proteina1 = al_load_bitmap ("Recursos/nutricao/Proteina1.png");
    ALLEGRO_BITMAP *proteina2 = al_load_bitmap ("Recursos/nutricao/Proteina2.png");
    ALLEGRO_BITMAP *reducaop1 = al_load_bitmap ("Recursos/nutricao/ReducaoPeso1.png");
    ALLEGRO_BITMAP *reducaop2 = al_load_bitmap ("Recursos/nutricao/ReducaoPeso2.png");
    ALLEGRO_BITMAP *ricosc1 = al_load_bitmap ("Recursos/nutricao/RicosCalcio1.png");
    ALLEGRO_BITMAP *ricosc2 = al_load_bitmap ("Recursos/nutricao/RicosCalcio2.png");

    //Primeiro botao
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(beberagua2, 100 , 200, 0);
    }
    else
    {
        al_draw_bitmap(beberagua1, 100, 200, 0);

    }
    // Segundo botao
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(ricosc2, 100, 280, 0);
    }
    else
    {
        al_draw_bitmap(ricosc1, 100, 280, 0);
    }
    // Terceiro botao
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(reducaop2, 100, 360, 0);
    }
    else
    {
        al_draw_bitmap(reducaop1, 100, 360, 0);
    }
    // Quarto botao
    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(gordura2, 100, 440, 0);
    }
    else
    {
        al_draw_bitmap(gordura1, 100, 440, 0);
    }
    //Quinto botao
    if (opcao_selecionada == 5)
    {
        al_draw_bitmap(cortarc2, 100, 520, 0);
    }
    else
    {
        al_draw_bitmap(cortarc1, 100, 520, 0);
    }
    // Sexto botao
    if(opcao_selecionada == 6)
    {

        al_draw_bitmap(boaa2, 600 , 200, 0);
    }
    else
    {
        al_draw_bitmap(boaa1, 600, 200, 0);

    }
    // Setimo Botao
    if (opcao_selecionada == 7)
    {
        al_draw_bitmap(proteina2, 600, 280, 0);
    }
    else
    {
        al_draw_bitmap(proteina1, 600, 280, 0);
    }
    // Oitavo Botao
    if (opcao_selecionada == 8)
    {
        al_draw_bitmap(comprarq2, 600, 360, 0);
    }
    else
    {
        al_draw_bitmap(comprarq1, 600, 360, 0);
    }
    // Nono Botao
    if (opcao_selecionada == 9)
    {
        al_draw_bitmap(carboidrato2, 600, 440, 0);
    }
    else
    {
        al_draw_bitmap(carboidrato1, 600, 440, 0);
    }
    //Decimo Botao
    if (opcao_selecionada == 10)
    {
        al_draw_bitmap(exerciciof2, 600, 520, 0);
    }
    else
    {
        al_draw_bitmap(exerciciof1, 600, 520, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (beberagua1);
    al_destroy_bitmap (beberagua2);
    al_destroy_bitmap (ricosc1);
    al_destroy_bitmap (ricosc2);
    al_destroy_bitmap (boaa1);
    al_destroy_bitmap (boaa2);
    al_destroy_bitmap (carboidrato1);
    al_destroy_bitmap (carboidrato2);
    al_destroy_bitmap (comprarq1);
    al_destroy_bitmap (comprarq2);
    al_destroy_bitmap (cortarc1);
    al_destroy_bitmap (cortarc2);
    al_destroy_bitmap (exerciciof1);
    al_destroy_bitmap (exerciciof2);
    al_destroy_bitmap (gordura1);
    al_destroy_bitmap (gordura2);
    al_destroy_bitmap (proteina1);
    al_destroy_bitmap (proteina2);
    al_destroy_bitmap (reducaop1);
    al_destroy_bitmap (reducaop2);
}
void monta_menuopcao(int opcao_selecionada)
{

    ALLEGRO_BITMAP *som1 = al_load_bitmap("Recursos/Opcoes/som1.png");
    ALLEGRO_BITMAP *som2 = al_load_bitmap("Recursos/Opcoes/som2.png");
    ALLEGRO_BITMAP *sobre1 = al_load_bitmap("Recursos/Opcoes/sobre1.png");
    ALLEGRO_BITMAP *sobre2 = al_load_bitmap("Recursos/Opcoes/sobre2.png");

    //Primeiro botao
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(som2, 350 , 310, 0);
    }
    else
    {
        al_draw_bitmap(som1, 350, 310, 0);

    }
    // Segundo botao
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(sobre2, 350, 430, 0);
    }
    else
    {
        al_draw_bitmap(sobre1, 350, 430, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (som1);
    al_destroy_bitmap (som2);
    al_destroy_bitmap (sobre1);
    al_destroy_bitmap (sobre2);

}
void mostra_opcao()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundoopcao;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundoopcao = al_load_bitmap("Recursos/Opcoes/fundoopcoes.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundoopcao, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundoopcao, 0, 0, 0);
        monta_menuopcao(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode ==
                        ALLEGRO_KEY_ESCAPE)
                {
                    sair = true;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 2)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 2)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 2)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu = 2;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 3)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_opcao_som();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_fundoSobre();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundoopcao);

    return 0;
}
void monta_menuopcao_som(int opcao_selecionada)
{

    ALLEGRO_BITMAP *sim1 = al_load_bitmap("Recursos/Opcoes/som/sim1.png");
    ALLEGRO_BITMAP *sim2 = al_load_bitmap("Recursos/Opcoes/som/sim2.png");
    ALLEGRO_BITMAP *nao1 = al_load_bitmap("Recursos/Opcoes/som/nao1.png");
    ALLEGRO_BITMAP *nao2 = al_load_bitmap("Recursos/Opcoes/som/nao2.png");

    //Primeiro botao
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(sim2, 350 , 350, 0);
    }
    else
    {
        al_draw_bitmap(sim1, 350, 350, 0);

    }
    // Segundo botao
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(nao2, 350, 430, 0);
    }
    else
    {
        al_draw_bitmap(nao1, 350, 430, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (sim1);
    al_destroy_bitmap (sim2);
    al_destroy_bitmap (nao1);
    al_destroy_bitmap (nao2);

}
void mostra_opcao_som()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundoopcaosom;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundoopcaosom = al_load_bitmap("Recursos/Opcoes/som/fundosom.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundoopcaosom, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        printf("%i\n",opcao_menu);
        al_draw_bitmap(fundoopcaosom, 0, 0, 0);
        monta_menuopcao_som(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {

                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 2)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu = 2;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 3)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        audio = true;
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        audio = false;
                        sair = true;
                    }
                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundoopcaosom);

    return 0;
}
void dica_nutricao()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundonutricao;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundonutricao = al_load_bitmap("Recursos/nutricao/fundonutricao.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundonutricao, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundonutricao, 0, 0, 0);
        monta_menunutricao(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode ==
                        ALLEGRO_KEY_ESCAPE)
                {
                    sair = true;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 10)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 10)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 10)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu = 10;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 11)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_nut_agua1();
                        mostra_nut_agua2();
                        mostra_nut_agua3();
                        mostra_nut_agua4();
                        mostra_nut_agua5();
                        mostra_nut_agua6();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_nut_calcio1();
                        mostra_nut_calcio2();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_nut_redp1();
                        mostra_nut_redp2();
                        mostra_nut_redp3();
                        mostra_nut_redp4();
                        mostra_nut_redp5();
                        mostra_nut_redp6();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_nut_gordura1();
                        mostra_nut_gordura2();
                        mostra_nut_gordura3();
                        mostra_nut_gordura4();
                        mostra_nut_gordura5();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 5)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_nut_calorias1();
                        mostra_nut_calorias2();
                        mostra_nut_calorias3();
                        mostra_nut_calorias4();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 6)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_nut_boaa1();
                        mostra_nut_boaa2();
                        mostra_nut_boaa3();
                        mostra_nut_boaa4();
                        mostra_nut_boaa5();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 7)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_nut_proteina1();
                        mostra_nut_proteina2();
                        mostra_nut_proteina3();
                        mostra_nut_proteina4();
                        mostra_nut_proteina5();
                        mostra_nut_proteina6();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 8)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_nut_qualidadea1();
                        mostra_nut_qualidadea2();
                        mostra_nut_qualidadea3();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 9)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_nut_carboidrato1();
                        mostra_nut_carboidrato2();
                        mostra_nut_carboidrato3();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 10)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_nut_atf1();
                        mostra_nut_atf2();
                        mostra_nut_atf3();
                        mostra_nut_atf4();
                        mostra_nut_atf5();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundonutricao);

    return 0;
}
void monta_menu(int opcao_selecionada)
{

    ALLEGRO_BITMAP *jogar1 = al_load_bitmap("Recursos/jogar1.png");
    ALLEGRO_BITMAP *jogar2 = al_load_bitmap("Recursos/jogar2.png");
    ALLEGRO_BITMAP *nutricao1 = al_load_bitmap("Recursos/nutricao1.png");
    ALLEGRO_BITMAP *nutricao2 = al_load_bitmap("Recursos/nutricao2.png");
    ALLEGRO_BITMAP *sair1 = al_load_bitmap ("Recursos/sair1.png");
    ALLEGRO_BITMAP *sair2 = al_load_bitmap ("Recursos/sair2.png");
    ALLEGRO_BITMAP *opcao1 = al_load_bitmap ("Recursos/opcao1.png");
    ALLEGRO_BITMAP *opcao2 = al_load_bitmap ("Recursos/opcao2.png");
    ALLEGRO_BITMAP *instrucao1 = al_load_bitmap ("Recursos/instrucao1.png");
    ALLEGRO_BITMAP *instrucao2 = al_load_bitmap ("Recursos/instrucao2.png");
    ALLEGRO_BITMAP *curiosidades1 = al_load_bitmap("Recursos/curiosidades1.png");
    ALLEGRO_BITMAP *curiosidades2 = al_load_bitmap("Recursos/curiosidades2.png");



    // Primeira opçao do menu inicar
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(jogar2, 512 - al_get_bitmap_width(jogar2) / 2,
                       380 - 10 - al_get_bitmap_height (jogar2) - al_get_bitmap_height(instrucao1) / 2,0);
    }
    else
    {
        al_draw_bitmap(jogar1, 512 - al_get_bitmap_width(jogar1) / 2,
                       380 - 10 - al_get_bitmap_height (jogar1) - al_get_bitmap_height(instrucao1) / 2,0);

    }
    // Segundo botao do menu instrucao
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(instrucao2, 512 - al_get_bitmap_width(instrucao2) / 2,
                       295  + al_get_bitmap_height(instrucao2) / 6, 0);
    }
    else
    {
        al_draw_bitmap(instrucao1, 512 - al_get_bitmap_width(instrucao1) / 2,
                       295   + al_get_bitmap_height(instrucao1) / 6, 0);
    }
    // Terceiro botao no menu opçao
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(opcao2, 512 - al_get_bitmap_width(opcao2) / 2,
                       351 + 10 + al_get_bitmap_height(opcao2) / 6, 0);
    }
    else
    {
        al_draw_bitmap(opcao1, 512 - al_get_bitmap_width(opcao1) / 2,
                       351 + 10 + al_get_bitmap_height(opcao1) / 6, 0);
    }
    // Quarto botao menu nutricao
    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(nutricao2, 512 - al_get_bitmap_width(nutricao2) / 2,
                       418 + 10 + al_get_bitmap_height(nutricao2) / 6, 0);
    }
    else
    {
        al_draw_bitmap(nutricao1, 512 - al_get_bitmap_width(nutricao1) / 2,
                       418  + 10 + al_get_bitmap_height(nutricao1) / 6, 0);
    }
    //Quinto botao menu curiosidades
    if (opcao_selecionada == 5)
    {
        al_draw_bitmap(curiosidades2, 512 - al_get_bitmap_width(curiosidades2) / 2,
                       486 + 10 + al_get_bitmap_height(curiosidades2) / 6, 0);
    }
    else
    {
        al_draw_bitmap(curiosidades1, 512 - al_get_bitmap_width(curiosidades1) / 2,
                       486  + 10 + al_get_bitmap_height(curiosidades1) / 6, 0);
    }
    // Sexto botao no menu sair
    if (opcao_selecionada == 6)
    {
        al_draw_bitmap(sair2, 512 - al_get_bitmap_width(sair2) / 2,
                       553 + 10 + al_get_bitmap_height(sair2) / 6, 0);
    }
    else
    {
        al_draw_bitmap(sair1, 512 - al_get_bitmap_width(sair1) / 2,
                       553  + 10 + al_get_bitmap_height(sair1) / 6, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (jogar1);
    al_destroy_bitmap (jogar2);
    al_destroy_bitmap (sair1);
    al_destroy_bitmap (sair2);
    al_destroy_bitmap (opcao1);
    al_destroy_bitmap (opcao2);
    al_destroy_bitmap (instrucao1);
    al_destroy_bitmap (instrucao2);
    al_destroy_bitmap (nutricao1);
    al_destroy_bitmap (nutricao2);
    al_destroy_bitmap (curiosidades1);
    al_destroy_bitmap (curiosidades2);


}
void monta_menufutp1(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futebol/p1/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futebol/p1/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futebol/p1/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futebol/p1/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap ("Recursos/Esportes/Futebol/p1/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap ("Recursos/Esportes/Futebol/p1/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap ("Recursos/Esportes/Futebol/p1/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap ("Recursos/Esportes/Futebol/p1/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futp1()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futebol/p1/p1.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    cont = 0;
    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutp1(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}

void monta_menufutp2(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futebol/p2/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futebol/p2/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futebol/p2/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futebol/p2/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futebol/p2/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futebol/p2/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futebol/p2/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futebol/p2/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futp2()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futebol/p2/p2.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutp2(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutp3(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futebol/p3/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futebol/p3/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futebol/p3/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futebol/p3/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futebol/p3/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futebol/p3/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futebol/p3/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futebol/p3/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futp3()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futebol/p3/p3.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutp3(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutp4(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futebol/p4/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futebol/p4/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futebol/p4/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futebol/p4/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futebol/p4/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futebol/p4/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futebol/p4/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futebol/p4/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futp4()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futebol/p4/p4.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());


    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutp4(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutp5(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futebol/p5/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futebol/p5/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futebol/p5/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futebol/p5/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futebol/p5/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futebol/p5/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futebol/p5/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futebol/p5/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futp5()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futebol/p5/p5.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());


    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutp5(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutp6(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futebol/p6/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futebol/p6/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futebol/p6/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futebol/p6/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futebol/p6/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futebol/p6/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futebol/p6/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futebol/p6/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futp6()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futebol/p6/p6.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutp6(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutp7(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futebol/p7/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futebol/p7/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futebol/p7/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futebol/p7/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futebol/p7/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futebol/p7/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futebol/p7/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futebol/p7/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futp7()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futebol/p7/p7.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());


    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutp7(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutp8(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futebol/p8/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futebol/p8/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futebol/p8/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futebol/p8/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futebol/p8/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futebol/p8/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futebol/p8/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futebol/p8/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futp8()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futebol/p8/p8.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());


    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutp8(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutp9(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futebol/p9/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futebol/p9/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futebol/p9/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futebol/p9/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futebol/p9/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futebol/p9/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futebol/p9/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futebol/p9/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futp9()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futebol/p9/p9.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());


    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutp9(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutp10(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futebol/p10/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futebol/p10/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futebol/p10/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futebol/p10/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futebol/p10/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futebol/p10/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futebol/p10/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futebol/p10/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}
void monta_futp10()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futebol/p10/p10.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());


    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutp10(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}

void monta_menufutsalp1(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futsal/p1/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futsal/p1/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futsal/p1/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futsal/p1/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap ("Recursos/Esportes/Futsal/p1/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap ("Recursos/Esportes/Futsal/p1/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap ("Recursos/Esportes/Futsal/p1/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap ("Recursos/Esportes/Futsal/p1/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futsalp1()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futsal/p1/p1.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    cont = 0;
    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutsalp1(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}

void monta_menufutsalp2(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futsal/p2/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futsal/p2/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futsal/p2/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futsal/p2/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futsal/p2/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futsal/p2/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futsal/p2/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futsal/p2/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futsalp2()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futsal/p2/p2.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutsalp2(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutsalp3(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futsal/p3/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futsal/p3/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futsal/p3/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futsal/p3/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futsal/p3/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futsal/p3/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futsal/p3/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futsal/p3/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futsalp3()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futsal/p3/p3.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutsalp3(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutsalp4(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futsal/p4/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futsal/p4/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futsal/p4/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futsal/p4/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futsal/p4/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futsal/p4/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futsal/p4/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futsal/p4/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futsalp4()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futsal/p4/p4.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutsalp4(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutsalp5(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futsal/p5/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futsal/p5/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futsal/p5/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futsal/p5/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futsal/p5/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futsal/p5/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futsal/p5/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futsal/p5/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futsalp5()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futsal/p5/p5.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutsalp5(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutsalp6(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futsal/p6/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futsal/p6/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futsal/p6/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futsal/p6/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futsal/p6/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futsal/p6/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futsal/p6/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futsal/p6/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futsalp6()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futsal/p6/p6.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutsalp6(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutsalp7(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futsal/p7/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futsal/p7/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futsal/p7/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futsal/p7/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futsal/p7/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futsal/p7/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futsal/p7/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futsal/p7/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futsalp7()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futsal/p7/p7.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutsalp7(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutsalp8(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futsal/p8/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futsal/p8/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futsal/p8/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futsal/p8/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futsal/p8/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futsal/p8/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futsal/p8/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futsal/p8/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futsalp8()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futsal/p8/p8.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutsalp8(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutsalp9(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futsal/p9/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futsal/p9/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futsal/p9/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futsal/p9/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futsal/p9/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futsal/p9/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futsal/p9/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futsal/p9/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_futsalp9()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futsal/p9/p9.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutsalp9(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menufutsalp10(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Futsal/p10/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Futsal/p10/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Futsal/p10/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Futsal/p10/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Futsal/p10/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Futsal/p10/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Futsal/p10/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Futsal/p10/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}
void monta_futsalp10()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Futsal/p10/p10.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menufutsalp10(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menubasquetep1(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Basquete/p1/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Basquete/p1/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Basquete/p1/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Basquete/p1/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap ("Recursos/Esportes/Basquete/p1/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap ("Recursos/Esportes/Basquete/p1/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap ("Recursos/Esportes/Basquete/p1/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap ("Recursos/Esportes/Basquete/p1/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_basquetep1()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Basquete/p1/p1.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    cont = 0;
    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menubasquetep1(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}

void monta_menubasquetep2(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Basquete/p2/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Basquete/p2/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Basquete/p2/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Basquete/p2/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Basquete/p2/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Basquete/p2/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Basquete/p2/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Basquete/p2/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_basquetep2()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Basquete/p2/p2.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menubasquetep2(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menubasquetep3(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Basquete/p3/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Basquete/p3/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Basquete/p3/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Basquete/p3/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Basquete/p3/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Basquete/p3/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Basquete/p3/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Basquete/p3/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_basquetep3()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Basquete/p3/p3.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menubasquetep3(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menubasquetep4(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Basquete/p4/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Basquete/p4/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Basquete/p4/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Basquete/p4/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Basquete/p4/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Basquete/p4/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Basquete/p4/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Basquete/p4/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_basquetep4()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Basquete/p4/p4.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menubasquetep4(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menubasquetep5(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Basquete/p5/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Basquete/p5/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Basquete/p5/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Basquete/p5/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Basquete/p5/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Basquete/p5/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Basquete/p5/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Basquete/p5/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_basquetep5()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Basquete/p5/p5.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menubasquetep5(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menubasquetep6(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Basquete/p6/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Basquete/p6/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Basquete/p6/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Basquete/p6/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Basquete/p6/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Basquete/p6/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Basquete/p6/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Basquete/p6/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_basquetep6()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Basquete/p6/p6.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menubasquetep6(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menubasquetep7(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Basquete/p7/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Basquete/p7/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Basquete/p7/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Basquete/p7/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Basquete/p7/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Basquete/p7/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Basquete/p7/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Basquete/p7/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_basquetep7()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Basquete/p7/p7.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menubasquetep7(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menubasquetep8(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Basquete/p8/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Basquete/p8/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Basquete/p8/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Basquete/p8/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Basquete/p8/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Basquete/p8/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Basquete/p8/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Basquete/p8/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_basquetep8()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Basquete/p8/p8.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menubasquetep8(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menubasquetep9(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Basquete/p9/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Basquete/p9/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Basquete/p9/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Basquete/p9/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Basquete/p9/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Basquete/p9/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Basquete/p9/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Basquete/p9/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_basquetep9()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Basquete/p9/p9.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menubasquetep9(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menubasquetep10(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Basquete/p10/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Basquete/p10/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Basquete/p10/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Basquete/p10/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Basquete/p10/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Basquete/p10/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Basquete/p10/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Basquete/p10/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}
void monta_basquetep10()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Basquete/p10/p10.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menubasquetep10(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}



void monta_menuatletismop1(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Basquete/p1/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Basquete/p1/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Basquete/p1/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Basquete/p1/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap ("Recursos/Esportes/Basquete/p1/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap ("Recursos/Esportes/Basquete/p1/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap ("Recursos/Esportes/Basquete/p1/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap ("Recursos/Esportes/Basquete/p1/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_atletismop1()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Atletismo/p1/p1.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    cont = 0;
    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuatletismop1(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}

void monta_menuatletismop2(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Atletismo/p2/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Atletismo/p2/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Atletismo/p2/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Atletismo/p2/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Atletismo/p2/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Atletismo/p2/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Atletismo/p2/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Atletismo/p2/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_atletismop2()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Atletismo/p2/p2.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuatletismop2(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuatletismop3(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Atletismo/p3/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Atletismo/p3/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Atletismo/p3/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Atletismo/p3/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Atletismo/p3/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Atletismo/p3/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Atletismo/p3/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Atletismo/p3/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_atletismop3()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Atletismo/p3/p3.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuatletismop3(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuatletismop4(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Atletismo/p4/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Atletismo/p4/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Atletismo/p4/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Atletismo/p4/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Atletismo/p4/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Atletismo/p4/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Atletismo/p4/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Atletismo/p4/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_atletismop4()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Atletismo/p4/p4.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuatletismop4(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuatletismop5(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Atletismo/p5/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Atletismo/p5/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Atletismo/p5/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Atletismo/p5/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Atletismo/p5/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Atletismo/p5/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Atletismo/p5/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Atletismo/p5/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_atletismop5()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Atletismo/p5/p5.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());


    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuatletismop5(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuatletismop6(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Atletismo/p6/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Atletismo/p6/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Atletismo/p6/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Atletismo/p6/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Atletismo/p6/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Atletismo/p6/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Atletismo/p6/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Atletismo/p6/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_atletismop6()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Atletismo/p6/p6.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuatletismop6(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuatletismop7(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Atletismo/p7/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Atletismo/p7/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Atletismo/p7/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Atletismo/p7/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Atletismo/p7/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Atletismo/p7/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Atletismo/p7/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Atletismo/p7/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_atletismop7()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Atletismo/p7/p7.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuatletismop7(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuatletismop8(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Atletismo/p8/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Atletismo/p8/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Atletismo/p8/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Atletismo/p8/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Atletismo/p8/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Atletismo/p8/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Atletismo/p8/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Atletismo/p8/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_atletismop8()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Atletismo/p8/p8.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuatletismop8(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuatletismop9(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Atletismo/p9/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Atletismo/p9/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Atletismo/p9/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Atletismo/p9/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Atletismo/p9/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Atletismo/p9/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Atletismo/p9/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Atletismo/p9/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_atletismop9()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Atletismo/p9/p9.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuatletismop9(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuatletismop10(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Atletismo/p10/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Atletismo/p10/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Atletismo/p10/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Atletismo/p10/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Atletismo/p10/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Atletismo/p10/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Atletismo/p10/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Atletismo/p10/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}
void monta_atletismop10()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Atletismo/p10/p10.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuatletismop10(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}




void monta_menuginasticap1(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Ginastica/p1/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Ginastica/p1/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Ginastica/p1/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Ginastica/p1/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap ("Recursos/Esportes/Ginastica/p1/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap ("Recursos/Esportes/Ginastica/p1/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap ("Recursos/Esportes/Ginastica/p1/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap ("Recursos/Esportes/Ginastica/p1/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_ginasticap1()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Ginastica/p1/p1.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    cont = 0;
    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuginasticap1(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}

void monta_menuginasticap2(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Ginastica/p2/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Ginastica/p2/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Ginastica/p2/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Ginastica/p2/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Ginastica/p2/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Ginastica/p2/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Ginastica/p2/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Ginastica/p2/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_ginasticap2()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Ginastica/p2/p2.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuginasticap2(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuginasticap3(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Ginastica/p3/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Ginastica/p3/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Ginastica/p3/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Ginastica/p3/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Ginastica/p3/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Ginastica/p3/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Ginastica/p3/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Ginastica/p3/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_ginasticap3()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Ginastica/p3/p3.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuginasticap3(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuginasticap4(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Ginastica/p4/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Ginastica/p4/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Ginastica/p4/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Ginastica/p4/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Ginastica/p4/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Ginastica/p4/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Ginastica/p4/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Ginastica/p4/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_ginasticap4()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Ginastica/p4/p4.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuginasticap4(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuginasticap5(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Ginastica/p5/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Ginastica/p5/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Ginastica/p5/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Ginastica/p5/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Ginastica/p5/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Ginastica/p5/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Ginastica/p5/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Ginastica/p5/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_ginasticap5()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Ginastica/p5/p5.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuginasticap5(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuginasticap6(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Ginastica/p6/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Ginastica/p6/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Ginastica/p6/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Ginastica/p6/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Ginastica/p6/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Ginastica/p6/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Ginastica/p6/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Ginastica/p6/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_ginasticap6()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Ginastica/p6/p6.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuginasticap6(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuginasticap7(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Ginastica/p7/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Ginastica/p7/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Ginastica/p7/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Ginastica/p7/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Ginastica/p7/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Ginastica/p7/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Ginastica/p7/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Ginastica/p7/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_ginasticap7()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Ginastica/p7/p7.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuginasticap7(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuginasticap8(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Ginastica/p8/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Ginastica/p8/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Ginastica/p8/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Ginastica/p8/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Ginastica/p8/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Ginastica/p8/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Ginastica/p8/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Ginastica/p8/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_ginasticap8()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Ginastica/p8/p8.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuginasticap8(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuginasticap9(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Ginastica/p9/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Ginastica/p9/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Ginastica/p9/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Ginastica/p9/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Ginastica/p9/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Ginastica/p9/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Ginastica/p9/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Ginastica/p9/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_ginasticap9()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Ginastica/p9/p9.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuginasticap9(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuginasticap10(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Ginastica/p10/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Ginastica/p10/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Ginastica/p10/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Ginastica/p10/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Ginastica/p10/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Ginastica/p10/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Ginastica/p10/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Ginastica/p10/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}
void monta_ginasticap10()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Ginastica/p10/p10.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuginasticap10(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}


void monta_menuhandebolp1(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Handebol/p1/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Handebol/p1/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Handebol/p1/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Handebol/p1/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap ("Recursos/Esportes/Handebol/p1/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap ("Recursos/Esportes/Handebol/p1/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap ("Recursos/Esportes/Handebol/p1/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap ("Recursos/Esportes/Handebol/p1/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_handebolp1()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Handebol/p1/p1.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    cont = 0;
    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuhandebolp1(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}

void monta_menuhandebolp2(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Handebol/p2/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Handebol/p2/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Handebol/p2/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Handebol/p2/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Handebol/p2/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Handebol/p2/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Handebol/p2/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Handebol/p2/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_handebolp2()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Handebol/p2/p2.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuhandebolp2(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuhandebolp3(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Handebol/p3/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Handebol/p3/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Handebol/p3/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Handebol/p3/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Handebol/p3/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Handebol/p3/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Handebol/p3/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Handebol/p3/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_handebolp3()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Handebol/p3/p3.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuhandebolp3(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuhandebolp4(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Handebol/p4/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Handebol/p4/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Handebol/p4/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Handebol/p4/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Handebol/p4/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Handebol/p4/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Handebol/p4/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Handebol/p4/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_handebolp4()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Handebol/p4/p4.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuhandebolp4(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuhandebolp5(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Handebol/p5/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Handebol/p5/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Handebol/p5/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Handebol/p5/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Handebol/p5/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Handebol/p5/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Handebol/p5/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Handebol/p5/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_handebolp5()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Handebol/p5/p5.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuhandebolp5(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuhandebolp6(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Handebol/p6/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Handebol/p6/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Handebol/p6/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Handebol/p6/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Handebol/p6/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Handebol/p6/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Handebol/p6/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Handebol/p6/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_handebolp6()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Handebol/p6/p6.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuhandebolp6(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuhandebolp7(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Handebol/p7/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Handebol/p7/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Handebol/p7/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Handebol/p7/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Handebol/p7/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Handebol/p7/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Handebol/p7/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Handebol/p7/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_handebolp7()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Handebol/p7/p7.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuhandebolp7(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuhandebolp8(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Handebol/p8/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Handebol/p8/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Handebol/p8/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Handebol/p8/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Handebol/p8/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Handebol/p8/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Handebol/p8/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Handebol/p8/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_handebolp8()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Handebol/p8/p8.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuhandebolp8(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuhandebolp9(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Handebol/p9/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Handebol/p9/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Handebol/p9/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Handebol/p9/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Handebol/p9/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Handebol/p9/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Handebol/p9/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Handebol/p9/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_handebolp9()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Handebol/p9/p9.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuhandebolp9(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuhandebolp10(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Handebol/p10/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Handebol/p10/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Handebol/p10/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Handebol/p10/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Handebol/p10/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Handebol/p10/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Handebol/p10/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Handebol/p10/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}
void monta_handebolp10()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Handebol/p10/p10.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuhandebolp10(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}



void monta_menujudop1(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Judo/p1/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Judo/p1/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Judo/p1/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Judo/p1/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap ("Recursos/Esportes/Judo/p1/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap ("Recursos/Esportes/Judo/p1/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap ("Recursos/Esportes/Judo/p1/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap ("Recursos/Esportes/Judo/p1/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_judop1()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Judo/p1/p1.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    cont = 0;
    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menujudop1(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}

void monta_menujudop2(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Judo/p2/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Judo/p2/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Judo/p2/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Judo/p2/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Judo/p2/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Judo/p2/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Judo/p2/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Judo/p2/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_judop2()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Judo/p2/p2.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menujudop2(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menujudop3(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Judo/p3/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Judo/p3/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Judo/p3/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Judo/p3/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Judo/p3/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Judo/p3/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Judo/p3/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Judo/p3/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_judop3()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Judo/p3/p3.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menujudop3(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menujudop4(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Judo/p4/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Judo/p4/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Judo/p4/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Judo/p4/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Judo/p4/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Judo/p4/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Judo/p4/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Judo/p4/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_judop4()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Judo/p4/p4.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menujudop4(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menujudop5(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Judo/p5/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Judo/p5/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Judo/p5/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Judo/p5/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Judo/p5/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Judo/p5/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Judo/p5/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Judo/p5/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_judop5()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Judo/p5/p5.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menujudop5(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menujudop6(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Judo/p6/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Judo/p6/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Judo/p6/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Judo/p6/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Judo/p6/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Judo/p6/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Judo/p6/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Judo/p6/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_judop6()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Judo/p6/p6.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menujudop6(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menujudop7(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Judo/p7/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Judo/p7/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Judo/p7/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Judo/p7/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Judo/p7/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Judo/p7/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Judo/p7/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Judo/p7/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_judop7()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Judo/p7/p7.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menujudop7(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menujudop8(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Judo/p8/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Judo/p8/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Judo/p8/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Judo/p8/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Judo/p8/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Judo/p8/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Judo/p8/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Judo/p8/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_judop8()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Judo/p8/p8.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menujudop8(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menujudop9(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Judo/p9/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Judo/p9/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Judo/p9/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Judo/p9/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Judo/p9/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Judo/p9/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Judo/p9/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Judo/p9/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_judop9()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Judo/p9/p9.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menujudop9(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menujudop10(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Judo/p10/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Judo/p10/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Judo/p10/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Judo/p10/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Judo/p10/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Judo/p10/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Judo/p10/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Judo/p10/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}
void monta_judop10()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Judo/p10/p10.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menujudop10(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}



void monta_menunatacaop1(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Natacao/p1/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Natacao/p1/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Natacao/p1/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Natacao/p1/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap ("Recursos/Esportes/Natacao/p1/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap ("Recursos/Esportes/Natacao/p1/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap ("Recursos/Esportes/Natacao/p1/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap ("Recursos/Esportes/Natacao/p1/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_natacaop1()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Natacao/p1/p1.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    cont = 0;
    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menunatacaop1(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}

void monta_menunatacaop2(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Natacao/p2/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Natacao/p2/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Natacao/p2/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Natacao/p2/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Natacao/p2/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Natacao/p2/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Natacao/p2/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Natacao/p2/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_natacaop2()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Natacao/p2/p2.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menunatacaop2(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menunatacaop3(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Natacao/p3/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Natacao/p3/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Natacao/p3/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Natacao/p3/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Natacao/p3/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Natacao/p3/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Natacao/p3/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Natacao/p3/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_natacaop3()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Natacao/p3/p3.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menunatacaop3(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menunatacaop4(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Natacao/p4/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Natacao/p4/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Natacao/p4/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Natacao/p4/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Natacao/p4/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Natacao/p4/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Natacao/p4/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Natacao/p4/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_natacaop4()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Natacao/p4/p4.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menunatacaop4(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menunatacaop5(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Natacao/p5/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Natacao/p5/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Natacao/p5/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Natacao/p5/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Natacao/p5/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Natacao/p5/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Natacao/p5/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Natacao/p5/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_natacaop5()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Natacao/p5/p5.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menunatacaop5(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menunatacaop6(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Natacao/p6/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Natacao/p6/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Natacao/p6/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Natacao/p6/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Natacao/p6/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Natacao/p6/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Natacao/p6/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Natacao/p6/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_natacaop6()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Natacao/p6/p6.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menunatacaop6(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menunatacaop7(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Natacao/p7/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Natacao/p7/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Natacao/p7/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Natacao/p7/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Natacao/p7/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Natacao/p7/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Natacao/p7/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Natacao/p7/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_natacaop7()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Natacao/p7/p7.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menunatacaop7(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menunatacaop8(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Natacao/p8/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Natacao/p8/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Natacao/p8/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Natacao/p8/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Natacao/p8/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Natacao/p8/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Natacao/p8/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Natacao/p8/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_natacaop8()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Natacao/p8/p8.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menunatacaop8(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menunatacaop9(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Natacao/p9/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Natacao/p9/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Natacao/p9/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Natacao/p9/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Natacao/p9/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Natacao/p9/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Natacao/p9/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Natacao/p9/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_natacaop9()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Natacao/p9/p9.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menunatacaop9(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menunatacaop10(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Natacao/p10/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Natacao/p10/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Natacao/p10/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Natacao/p10/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Natacao/p10/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Natacao/p10/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Natacao/p10/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Natacao/p10/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}
void monta_natacaop10()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Natacao/p10/p10.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menunatacaop10(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}


void monta_menutenisp1(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Tenis/p1/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Tenis/p1/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Tenis/p1/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Tenis/p1/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap ("Recursos/Esportes/Tenis/p1/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap ("Recursos/Esportes/Tenis/p1/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap ("Recursos/Esportes/Tenis/p1/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap ("Recursos/Esportes/Tenis/p1/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_tenisp1()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Tenis/p1/p1.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    cont = 0;
    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menutenisp1(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}

void monta_menutenisp2(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Tenis/p2/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Tenis/p2/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Tenis/p2/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Tenis/p2/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Tenis/p2/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Tenis/p2/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Tenis/p2/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Tenis/p2/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_tenisp2()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Tenis/p2/p2.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menutenisp2(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menutenisp3(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Tenis/p3/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Tenis/p3/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Tenis/p3/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Tenis/p3/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Tenis/p3/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Tenis/p3/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Tenis/p3/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Tenis/p3/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_tenisp3()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Tenis/p3/p3.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menutenisp3(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menutenisp4(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Tenis/p4/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Tenis/p4/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Tenis/p4/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Tenis/p4/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Tenis/p4/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Tenis/p4/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Tenis/p4/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Tenis/p4/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_tenisp4()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Tenis/p4/p4.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menutenisp4(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menutenisp5(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Tenis/p5/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Tenis/p5/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Tenis/p5/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Tenis/p5/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Tenis/p5/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Tenis/p5/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Tenis/p5/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Tenis/p5/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_tenisp5()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Tenis/p5/p5.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menutenisp5(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menutenisp6(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Tenis/p6/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Tenis/p6/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Tenis/p6/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Tenis/p6/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Tenis/p6/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Tenis/p6/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Tenis/p6/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Tenis/p6/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_tenisp6()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Tenis/p6/p6.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menutenisp6(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menutenisp7(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Tenis/p7/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Tenis/p7/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Tenis/p7/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Tenis/p7/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Tenis/p7/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Tenis/p7/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Tenis/p7/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Tenis/p7/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_tenisp7()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Tenis/p7/p7.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menutenisp7(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menutenisp8(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Tenis/p8/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Tenis/p8/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Tenis/p8/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Tenis/p8/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Tenis/p8/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Tenis/p8/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Tenis/p8/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Tenis/p8/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_tenisp8()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Tenis/p8/p8.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menutenisp8(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menutenisp9(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Tenis/p9/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Tenis/p9/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Tenis/p9/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Tenis/p9/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Tenis/p9/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Tenis/p9/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Tenis/p9/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Tenis/p9/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_tenisp9()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Tenis/p9/p9.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menutenisp9(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menutenisp10(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Tenis/p10/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Tenis/p10/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Tenis/p10/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Tenis/p10/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Tenis/p10/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Tenis/p10/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Tenis/p10/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Tenis/p10/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}
void monta_tenisp10()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Tenis/p10/p10.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menutenisp10(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}

void monta_menuvoleip1(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Volei/p1/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Volei/p1/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Volei/p1/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Volei/p1/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap ("Recursos/Esportes/Volei/p1/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap ("Recursos/Esportes/Volei/p1/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap ("Recursos/Esportes/Volei/p1/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap ("Recursos/Esportes/Volei/p1/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_voleip1()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Volei/p1/p1.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    cont = 0;
    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuvoleip1(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}

void monta_menuvoleip2(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Volei/p2/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Volei/p2/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Volei/p2/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Volei/p2/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Volei/p2/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Volei/p2/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Volei/p2/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Volei/p2/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_voleip2()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Volei/p2/p2.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuvoleip2(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuvoleip3(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Volei/p3/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Volei/p3/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Volei/p3/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Volei/p3/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Volei/p3/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Volei/p3/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Volei/p3/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Volei/p3/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_voleip3()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Volei/p3/p3.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuvoleip3(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuvoleip4(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Volei/p4/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Volei/p4/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Volei/p4/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Volei/p4/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Volei/p4/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Volei/p4/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Volei/p4/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Volei/p4/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_voleip4()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Volei/p4/p4.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuvoleip4(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuvoleip5(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Volei/p5/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Volei/p5/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Volei/p5/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Volei/p5/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Volei/p5/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Volei/p5/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Volei/p5/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Volei/p5/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_voleip5()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Volei/p5/p5.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuvoleip5(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuvoleip6(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Volei/p6/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Volei/p6/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Volei/p6/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Volei/p6/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Volei/p6/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Volei/p6/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Volei/p6/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Volei/p6/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_voleip6()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Volei/p6/p6.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuvoleip6(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuvoleip7(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Volei/p7/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Volei/p7/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Volei/p7/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Volei/p7/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Volei/p7/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Volei/p7/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Volei/p7/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Volei/p7/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_voleip7()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Volei/p7/p7.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuvoleip7(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuvoleip8(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Volei/p8/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Volei/p8/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Volei/p8/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Volei/p8/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Volei/p8/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Volei/p8/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Volei/p8/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Volei/p8/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_voleip8()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Volei/p8/p8.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuvoleip8(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuvoleip9(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Volei/p9/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Volei/p9/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Volei/p9/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Volei/p9/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Volei/p9/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Volei/p9/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Volei/p9/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Volei/p9/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}

void monta_voleip9()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Volei/p9/p9.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuvoleip9(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void monta_menuvoleip10(int opcao_selecionada)
{

    ALLEGRO_BITMAP *perguntaa1 = al_load_bitmap("Recursos/Esportes/Volei/p10/a1.png");
    ALLEGRO_BITMAP *perguntaa2 = al_load_bitmap("Recursos/Esportes/Volei/p10/a2.png");
    ALLEGRO_BITMAP *perguntab1 = al_load_bitmap("Recursos/Esportes/Volei/p10/b1.png");
    ALLEGRO_BITMAP *perguntab2 = al_load_bitmap("Recursos/Esportes/Volei/p10/b2.png");
    ALLEGRO_BITMAP *perguntac1 = al_load_bitmap("Recursos/Esportes/Volei/p10/c1.png");
    ALLEGRO_BITMAP *perguntac2 = al_load_bitmap("Recursos/Esportes/Volei/p10/c2.png");
    ALLEGRO_BITMAP *perguntad1 = al_load_bitmap("Recursos/Esportes/Volei/p10/d1.png");
    ALLEGRO_BITMAP *perguntad2 = al_load_bitmap("Recursos/Esportes/Volei/p10/d2.png");


    // Primeira opçao do menu
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(perguntaa2, 50, 200, 0);
    }
    else
    {
        al_draw_bitmap(perguntaa1, 50, 200, 0);

    }
    // Segundo botao do menu
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(perguntab2, 50, 300, 0);
    }
    else
    {
        al_draw_bitmap(perguntab1, 50, 300, 0);
    }
    // Terceiro botao no menu
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(perguntac2, 50, 400, 0);
    }
    else
    {
        al_draw_bitmap(perguntac1, 50, 400, 0);
    }
    //Quarto botao menu

    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(perguntad2, 50, 500, 0);
    }
    else
    {
        al_draw_bitmap(perguntad1, 50, 500, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (perguntaa1);
    al_destroy_bitmap (perguntaa2);
    al_destroy_bitmap (perguntab1);
    al_destroy_bitmap (perguntab2);
    al_destroy_bitmap (perguntac1);
    al_destroy_bitmap (perguntac2);
    al_destroy_bitmap (perguntad1);
    al_destroy_bitmap (perguntad2);
}
void monta_voleip10()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundopergunta1;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundopergunta1 = al_load_bitmap("Recursos/Esportes/Volei/p10/p10.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundopergunta1, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundopergunta1, 0, 0, 0);
        monta_menuvoleip10(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 4)
                    {
                        opcao_menu = 1;
                    }
                }

                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu =4;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 5)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_certo();
                        cont++;
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_errado();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        sair = true;
                    }

                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundopergunta1);

    return 0;
}
void mostra_reg_atletismo1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Atletismo/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_atletismo2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Atletismo/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_atletismo3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Atletismo/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_atletismo4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Atletismo/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_atletismo5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Atletismo/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_atletismo6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Atletismo/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_atletismo7()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Atletismo/pag7.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_atletismo8()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Atletismo/pag8.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_basquete1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Basquete/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_basquete2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Basquete/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_basquete3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Basquete/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_basquete4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Basquete/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_basquete5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Basquete/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_basquete6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Basquete/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_basquete7()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Basquete/pag7.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);
        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_basquete8()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Basquete/pag8.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futebol1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futebol/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futebol2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futebol/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futebol3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futebol/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futebol4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futebol/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futebol5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futebol/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futebol6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futebol/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futebol7()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futebol/pag7.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futebol8()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futebol/pag8.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);
        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futebol9()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futebol/pag9.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futebol10()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futebol/pag10.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futebol11()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futebol/pag11.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futsal1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futsal/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futsal2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futsal/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futsal3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futsal/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futsal4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futsal/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futsal5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futsal/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futsal6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futsal/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futsal7()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futsal/pag7.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futsal8()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futsal/pag8.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_futsal9()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Futsal/pag9.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_ginastica1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Ginastica/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_ginastica2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Ginastica/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_ginastica3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Ginastica/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_ginastica4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Ginastica/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);
        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_ginastica5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Ginastica/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_ginastica6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Ginastica/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_ginastica7()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Ginastica/pag7.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_ginastica8()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Ginastica/pag8.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_ginastica9()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Ginastica/pag9.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_ginastica10()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Ginastica/pag10.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_ginastica11()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Ginastica/pag11.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_ginastica12()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Ginastica/pag12.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_handebol1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Handebol/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_handebol2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Handebol/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_handebol3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Handebol/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_handebol4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Handebol/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_handebol5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Handebol/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_handebol6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Handebol/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_handebol7()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Handebol/pag7.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_judo1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Judo/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_judo2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Judo/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_judo3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Judo/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_judo4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Judo/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_judo5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Judo/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_judo6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Judo/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_judo7()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Judo/pag7.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_natacao1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Natacao/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_natacao2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Natacao/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_natacao3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Natacao/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_natacao4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Natacao/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_natacao5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Natacao/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_tenis1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Tenis/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_tenis2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Tenis/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_tenis3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Tenis/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_tenis4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Tenis/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_tenis5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Tenis/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_tenis6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Tenis/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);
        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_tenis7()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Tenis/pag7.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_tenis8()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Tenis/pag8.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);
        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_tenis9()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Tenis/pag9.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_volei1()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Volei/pag1.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_volei2()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Volei/pag2.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_volei3()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Volei/pag3.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_volei4()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Volei/pag4.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_volei5()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Volei/pag5.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_volei6()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Volei/pag6.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_volei7()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Volei/pag7.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_volei8()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Volei/pag8.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void mostra_reg_volei9()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundo1;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundo1 = al_load_bitmap("Recursos/Regras/Volei/pag9.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundo1, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundo1);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    sair = true;
                }
            }
        }
    }
}
void monta_menubiblioteca(int opcao_selecionada)
{

    ALLEGRO_BITMAP *atletismo1 = al_load_bitmap("Recursos/Regras/atletismo1.png");
    ALLEGRO_BITMAP *atletismo2 = al_load_bitmap("Recursos/Regras/atletismo2.png");
    ALLEGRO_BITMAP *basquete1 = al_load_bitmap("Recursos/Regras/basquete1.png");
    ALLEGRO_BITMAP *basquete2 = al_load_bitmap("Recursos/Regras/basquete2.png");
    ALLEGRO_BITMAP *futebol1 = al_load_bitmap ("Recursos/Regras/futebol1.png");
    ALLEGRO_BITMAP *futebol2 = al_load_bitmap ("Recursos/Regras/futebol2.png");
    ALLEGRO_BITMAP *futsal1 = al_load_bitmap ("Recursos/Regras/futsal1.png");
    ALLEGRO_BITMAP *futsal2 = al_load_bitmap ("Recursos/Regras/futsal2.png");
    ALLEGRO_BITMAP *ginastica1 = al_load_bitmap ("Recursos/Regras/ginastica1.png");
    ALLEGRO_BITMAP *ginastica2 = al_load_bitmap ("Recursos/Regras/ginastica2.png");
    ALLEGRO_BITMAP *handebol1 = al_load_bitmap("Recursos/Regras/handebol1.png");
    ALLEGRO_BITMAP *handebol2 = al_load_bitmap("Recursos/Regras/handebol2.png");
    ALLEGRO_BITMAP *judo1 = al_load_bitmap ("Recursos/Regras/judo1.png");
    ALLEGRO_BITMAP *judo2 = al_load_bitmap ("Recursos/Regras/judo2.png");
    ALLEGRO_BITMAP *natacao1 = al_load_bitmap ("Recursos/Regras/natacao1.png");
    ALLEGRO_BITMAP *natacao2 = al_load_bitmap ("Recursos/Regras/natacao2.png");
    ALLEGRO_BITMAP *tenis1 = al_load_bitmap ("Recursos/Regras/tenis1.png");
    ALLEGRO_BITMAP *tenis2 = al_load_bitmap ("Recursos/Regras/tenis2.png");
    ALLEGRO_BITMAP *volei1 = al_load_bitmap ("Recursos/Regras/volei1.png");
    ALLEGRO_BITMAP *volei2 = al_load_bitmap ("Recursos/Regras/volei2.png");

    //Primeiro botao
    if(opcao_selecionada == 1)
    {

        al_draw_bitmap(atletismo2, 100 , 200, 0);
    }
    else
    {
        al_draw_bitmap(atletismo1, 100, 200, 0);

    }
    // Segundo botao
    if (opcao_selecionada == 2)
    {
        al_draw_bitmap(basquete2, 100, 280, 0);
    }
    else
    {
        al_draw_bitmap(basquete1, 100, 280, 0);
    }
    // Terceiro botao
    if (opcao_selecionada == 3)
    {
        al_draw_bitmap(futebol2, 100, 360, 0);
    }
    else
    {
        al_draw_bitmap(futebol1, 100, 360, 0);
    }
    // Quarto botao
    if (opcao_selecionada == 4)
    {
        al_draw_bitmap(futsal2, 100, 440, 0);
    }
    else
    {
        al_draw_bitmap(futsal1, 100, 440, 0);
    }
    //Quinto botao
    if (opcao_selecionada == 5)
    {
        al_draw_bitmap(ginastica2, 100, 520, 0);
    }
    else
    {
        al_draw_bitmap(ginastica1, 100, 520, 0);
    }
    // Sexto botao
    if(opcao_selecionada == 6)
    {

        al_draw_bitmap(handebol2, 600 , 200, 0);
    }
    else
    {
        al_draw_bitmap(handebol1, 600, 200, 0);

    }
    // Setimo Botao
    if (opcao_selecionada == 7)
    {
        al_draw_bitmap(judo2, 600, 280, 0);
    }
    else
    {
        al_draw_bitmap(judo1, 600, 280, 0);
    }
    // Oitavo Botao
    if (opcao_selecionada == 8)
    {
        al_draw_bitmap(natacao2, 600, 360, 0);
    }
    else
    {
        al_draw_bitmap(natacao1, 600, 360, 0);
    }
    // Nono Botao
    if (opcao_selecionada == 9)
    {
        al_draw_bitmap(tenis2, 600, 440, 0);
    }
    else
    {
        al_draw_bitmap(tenis1, 600, 440, 0);
    }
    //Decimo Botao
    if (opcao_selecionada == 10)
    {
        al_draw_bitmap(volei2, 600, 520, 0);
    }
    else
    {
        al_draw_bitmap(volei1, 600, 520, 0);
    }

    //limpa a memoria, destroi as imagens

    al_destroy_bitmap (atletismo1);
    al_destroy_bitmap (atletismo2);
    al_destroy_bitmap (basquete1);
    al_destroy_bitmap (basquete2);
    al_destroy_bitmap (futebol1);
    al_destroy_bitmap (futebol2);
    al_destroy_bitmap (futsal1);
    al_destroy_bitmap (futsal2);
    al_destroy_bitmap (ginastica1);
    al_destroy_bitmap (ginastica2);
    al_destroy_bitmap (handebol1);
    al_destroy_bitmap (handebol2);
    al_destroy_bitmap (judo1);
    al_destroy_bitmap (judo2);
    al_destroy_bitmap (natacao1);
    al_destroy_bitmap (natacao2);
    al_destroy_bitmap (tenis1);
    al_destroy_bitmap (tenis2);
    al_destroy_bitmap (volei1);
    al_destroy_bitmap (volei2);
}
void regras_biblioteca()
{

    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo;
    // Inicializa a biblioteca
    fila_eventos = al_create_event_queue();
    // Carregar a imagem de fundo
    fundo = al_load_bitmap("Recursos/Regras/FundoEsportes1.jpg");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundo, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();

    al_register_event_source(fila_eventos,al_get_keyboard_event_source());

    int opcao_menu = 1;
    bool sair = false;
    while (sair == false)
    {
        al_draw_bitmap(fundo, 0, 0, 0);
        monta_menubiblioteca(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode ==
                        ALLEGRO_KEY_ESCAPE)
                {
                    sair = true;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 10)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 10)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 10)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu = 10;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {
                    if (opcao_menu == 11)
                    {
                        sair = true;
                    }
                    else if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_reg_atletismo1();
                        mostra_reg_atletismo2();
                        mostra_reg_atletismo3();
                        mostra_reg_atletismo4();
                        mostra_reg_atletismo5();
                        mostra_reg_atletismo6();
                        mostra_reg_atletismo7();
                        mostra_reg_atletismo8();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_reg_basquete1();
                        mostra_reg_basquete2();
                        mostra_reg_basquete3();
                        mostra_reg_basquete4();
                        mostra_reg_basquete5();
                        mostra_reg_basquete6();
                        mostra_reg_basquete7();
                        mostra_reg_basquete8();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_reg_futebol1();
                        mostra_reg_futebol2();
                        mostra_reg_futebol3();
                        mostra_reg_futebol4();
                        mostra_reg_futebol5();
                        mostra_reg_futebol6();
                        mostra_reg_futebol7();
                        mostra_reg_futebol8();
                        mostra_reg_futebol9();
                        mostra_reg_futebol10();
                        mostra_reg_futebol11();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_reg_futsal1();
                        mostra_reg_futsal2();
                        mostra_reg_futsal3();
                        mostra_reg_futsal4();
                        mostra_reg_futsal5();
                        mostra_reg_futsal6();
                        mostra_reg_futsal7();
                        mostra_reg_futsal8();
                        mostra_reg_futsal9();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 5)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_reg_ginastica1();
                        mostra_reg_ginastica2();
                        mostra_reg_ginastica3();
                        mostra_reg_ginastica4();
                        mostra_reg_ginastica5();
                        mostra_reg_ginastica6();
                        mostra_reg_ginastica7();
                        mostra_reg_ginastica8();
                        mostra_reg_ginastica9();
                        mostra_reg_ginastica10();
                        mostra_reg_ginastica11();
                        mostra_reg_ginastica12();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 6)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_reg_handebol1();
                        mostra_reg_handebol2();
                        mostra_reg_handebol3();
                        mostra_reg_handebol4();
                        mostra_reg_handebol5();
                        mostra_reg_handebol6();
                        mostra_reg_handebol7();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 7)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_reg_judo1();
                        mostra_reg_judo2();
                        mostra_reg_judo3();
                        mostra_reg_judo4();
                        mostra_reg_judo5();
                        mostra_reg_judo6();
                        mostra_reg_judo7();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 8)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_reg_natacao1();
                        mostra_reg_natacao2();
                        mostra_reg_natacao3();
                        mostra_reg_natacao4();
                        mostra_reg_natacao5();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 9)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_reg_tenis1();
                        mostra_reg_tenis2();
                        mostra_reg_tenis3();
                        mostra_reg_tenis4();
                        mostra_reg_tenis5();
                        mostra_reg_tenis6();
                        mostra_reg_tenis7();
                        mostra_reg_tenis8();
                        mostra_reg_tenis9();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 10)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_reg_volei1();
                        mostra_reg_volei2();
                        mostra_reg_volei3();
                        mostra_reg_volei4();
                        mostra_reg_volei5();
                        mostra_reg_volei6();
                        mostra_reg_volei7();
                        mostra_reg_volei8();
                        mostra_reg_volei9();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundo);

    return 0;
}

void mostra_fundoSobre()
{
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();
    al_register_event_source (fila_eventos, al_get_keyboard_event_source());  // Adicionar o teclado
    ALLEGRO_BITMAP *fundoSobre;// Declara a imagem de fundo

    srand(time( NULL));

    double tempo_inicial, tempo_final;
    bool sair = false;


    while (sair == false)
    {
        tempo_inicial = al_get_time();

        fundoSobre = al_load_bitmap("Recursos/fundoSobre.jpg");
        // Desenhar a imagem na tela
        al_draw_bitmap(fundoSobre, 0, 0, 0);

        // Aplica as alterações na tela
        al_flip_display();

        al_destroy_bitmap (fundoSobre);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                {
                    sair = true;
                }
            }
        }
    }
}

int main()
{
    // Declara a janela do aplicativo
    ALLEGRO_DISPLAY *janela;
    // Variável para controlar os eventos
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    // Declara a imagem de fundo
    ALLEGRO_BITMAP *fundo;
    // Inicializa a biblioteca


    al_init();
    // Inicializa o módulo de imagens
    al_init_image_addon();
    // Inicializando o teclado
    al_install_keyboard();
    // Inicializa o mouse
    al_install_mouse();
    // Inicializar o áudio
    al_install_audio();
    // Inicializar a parte de codecs de áudio
    al_init_acodec_addon();
    // Reservar samples
    al_reserve_samples(1);
    // Inicializar o modulo de primativas graficas
    al_init_primitives_addon();

    //cria fontes
    al_init_font_addon();
    // Cria a fila de eventos
    fila_eventos = al_create_event_queue();
    //comando para deixar a imagem no tamanho desejado
    janela = al_create_display(1024, 700);
    //carrega abertura
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    //abertura();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    // Carregar a imagem de fundo
    fundo = al_load_bitmap("Recursos/fundo1.jpg");
    // Variável que representa a música de fundo
    ALLEGRO_AUDIO_STREAM *musica = al_load_audio_stream("Recursos/music.ogg",4, 1024);
    // Carregar a música
    al_attach_audio_stream_to_mixer(musica,al_get_default_mixer());
    al_set_audio_stream_playing(musica, true);
    al_set_window_title(janela, "TecEdu Esportes");
    // Desenhar a imagem na tela
    al_draw_bitmap(fundo, 0, 0, 0);
    // Aplica as alterações na tela
    al_flip_display();
    // A fila de eventos receberá os eventos da janela
    al_register_event_source(fila_eventos,al_get_display_event_source(janela));
    al_register_event_source(fila_eventos,al_get_keyboard_event_source());


    // Música, comecea tocar!


    int opcao_menu = 1;
    bool sair = false;

    while (sair == false)
    {
        al_draw_bitmap(fundo, 0, 0, 0);
        if(audio == true)
        {
            al_set_audio_stream_playing(musica, true);
        }
        else if ( audio == false)
        {
            al_set_audio_stream_playing(musica, false);
        }
        monta_menu(opcao_menu);
        al_flip_display();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (evento.keyboard.keycode ==
                        ALLEGRO_KEY_ESCAPE)
                {
                    sair = true;
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 6)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 6)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                {
                    opcao_menu++;
                    if (opcao_menu > 6)
                    {
                        opcao_menu = 1;
                    }
                }
                else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                {
                    opcao_menu --;
                    if (opcao_menu < 1)
                    {
                        opcao_menu = 6;
                    }
                }
                else if ( evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {

                    if (opcao_menu == 1)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_escolha_avatar();//Opcao Avatar
                        mostra_jogo0();//tela de instrucao inicial
                        mostra_jogo();//tela da frente da escola
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 2)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_tutorial1();
                        mostra_tutorial2();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }

                    else if (opcao_menu == 3)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        mostra_opcao();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 4)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        dica_nutricao();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 5)
                    {
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        monta_curiosidades();
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    }
                    else if (opcao_menu == 6)
                    {
                        sair = true;
                    }
                }
            }
        }
    }
    // Libera a memória usada pela imagem de fundo
    al_destroy_bitmap(fundo);
    // Libera a memória usada pela janela
    al_destroy_display(janela);

    return 0;

}

const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 700;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_BITMAP *fundo = NULL;
ALLEGRO_BITMAP *fundo2 = NULL;

void fadeout(int velocidade);
void fadein(ALLEGRO_BITMAP *imagem, int velocidade);
bool inicializar();

int abertura()
{
    if (!inicializar())
    {
        return -1;
    }

    fadein(fundo, 1);
    fadein(fundo2, 2);
    al_rest(3.0);
    fadeout(1);

    return 0;
}

void fadeout(int velocidade)
{
    ALLEGRO_BITMAP *buffer = NULL;
    buffer = al_create_bitmap(LARGURA_TELA, ALTURA_TELA);
    al_set_target_bitmap(buffer);
    al_draw_bitmap(al_get_backbuffer(janela), 0, 0, 0);
    al_set_target_bitmap(al_get_backbuffer(janela));

    if (velocidade <= 0)
    {
        velocidade = 1;
    }
    else if (velocidade > 15)
    {
        velocidade = 15;
    }

    int alfa;
    for (alfa = 0; alfa <= 255; alfa += velocidade)
    {
        al_clear_to_color(al_map_rgba(0, 0, 0, 0));
        al_draw_tinted_bitmap(buffer, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 0);
        al_flip_display();
        al_rest(0.005);
    }

    al_destroy_bitmap(buffer);
}

void fadein(ALLEGRO_BITMAP *imagem, int velocidade)
{
    if (velocidade < 0)
    {
        velocidade = 1;
    }
    else if (velocidade > 15)
    {
        velocidade = 15;
    }

    int alfa;
    for (alfa = 0; alfa <= 255; alfa += velocidade)
    {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_tinted_bitmap(imagem, al_map_rgba(alfa, alfa, alfa, alfa), 0, 0, 0);
        al_flip_display();
        al_rest(0.005);
    }
}

bool inicializar()
{
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    fundo = al_load_bitmap("Recursos/abertura.jpg");
    fundo2 = al_load_bitmap("Recursos/patrocinio.jpg");
    return true;
}
