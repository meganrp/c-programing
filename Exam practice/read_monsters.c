#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 128

typedef struct {
    char *name;
    int hp;
    int ac;
} monster_t;

void trim(char *str) {
    int l = strlen(str);

    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

monster_t *parse_monster(char *csv_line) {
    char *token = strtok(csv_line, ",");
    int num_tokens = 0;

    monster_t *m = calloc(1, sizeof(monster_t));

    while (token != NULL) {
        switch (num_tokens) {
            case 0:
                m->name = calloc(strlen(token) + 1, sizeof(char));
                strcpy(m->name, token); 
                //m->name = token;
                //printf("%s\n", token);
                //printf("%s\n", m->name);
                break;
            case 1:
                m->hp = atoi(token);
                break;
            case 2:
                m->ac = atoi(token);
                break;
        }

        num_tokens++;
        token = strtok(NULL, ",");
    }

    if (num_tokens != 3) {
            m = NULL;
            free(m);
    }

    return m;
}

void print_monsters(monster_t **monsters, int num_monsters) {
    for (int i = 0; i < num_monsters; i++) {
        printf("Name: %s\nHP:   %d\nAC:   %d\n", monsters[i]->name, monsters[i]->hp, monsters[i]->ac);
    }
}

int main() {
    FILE *fp = fopen("monsters.csv", "r");

    if (fp == NULL) {
        printf("[ERROR]: monsters.csv must be present in the same directory.\n");
        return 1;
    }

    char buffer[BUF_SIZE] = { 0 };
    monster_t **monsters = NULL;
    int num_monsters = 0;

    while (fgets(buffer, BUF_SIZE, fp)) {
        trim(buffer);
        monster_t *m = parse_monster(buffer);
        //printf("%s\n", m->name);

        if (m != NULL) {
            monsters = realloc(monsters, sizeof(void *) * (num_monsters + 1));
            monsters[num_monsters] = m;
            //printf("%i\n", num_monsters);
            //printf("%s\n", monsters[num_monsters]->name);
            num_monsters++;
        }
        //printf("%s\n", monsters[0]->name);
    }
    //printf("%s\n", monsters[0]->name);
    //printf("%s\n", monsters[1]->name);
    print_monsters(monsters, num_monsters);

    free(monsters);

    fclose(fp);
}
