#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int dat;
	struct node *a[26];
};

struct node* new_node(struct node *h)
{
	int i;
	h = (struct node *)malloc(sizeof(struct node));

	for (i = 0; i < 26; i++)
		h->a[i] = 0;
	return h;
}

struct node* insert(struct node *h, char *s, int value)
{
	int i;
	struct node *p;

	if (strlen(s) == 0)
		return h;
	if (h == NULL)
		h = new_node(h);

	p = h;

	for (i = 0; i < strlen(s); i++) {
		if (p->a[s[i] - 'a'] == NULL)
			p->a[s[i] - 'a'] = (struct node *)malloc(sizeof(struct node));
		p = p->a[s[i] - 'a'];
	}
	p->dat = value;

	return h;
}

int dfs(struct node *h, char *data)
{
	int i;
	char q[100] = {0};
	char b[2] = {0};

	if (h == NULL)
		return 0;
	if (h ->dat > 0)
		printf("Match: %s\n", data);

	for(i = 0; i < 26; i++) {
		strcpy(q, data);
		b[0] = i + 'a';
		b[1] = '\0';
		strcat(q,b);
		dfs(h->a[i], q);
	}
}

void search(struct node *h, char *t, char *data)
{
	int i;
	char l[100] = {0};
	char b[2];

	strcpy(l, data);

	if (strlen(t) > 0) {
		b[0] = t[0];
		b[1] = '\0';

		if(h->a[b[0] - 'a'] != NULL) {
			strcat(data, b);
			search(h->a[b[0] - 'a'], t+1, data);
		} else {
			printf("No Match");
		}
	} else {
		if (h->dat != 0)
			printf("Match: ");

		for (i = 0; i < 26; i++) {
			strcpy(l, data);
			b[0] = i + 'a';
			b[1] = '\0';
			strcat(l, b);
			dfs(h->a[i], l);
		}
	}
}


int main()
{
	struct node *h = 0;

	h = insert(h, "angel", 12);
	h = insert(h, "angle", 9);
	h = insert(h, "ant", 23);
    h = insert(h, "animal", 5);
    h = insert(h, "any", 7);

	char t[] = "ang";

	char data[100] = "";

	search(h,t,data);

    return 0;
}

