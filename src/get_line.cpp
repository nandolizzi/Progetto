#include "get_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_MAXLINE 256

static int endOfLine(FILE *fin, int c)
{
  int eol = (c=='\r' || c=='\n');
  if (c == '\r')
  {
    c = getc(fin);
    if (c != '\n' && c != EOF)
      ungetc(c, fin);
  }
  return eol;
}


char *getLine(FILE *fin)
{
	int i, c;
	char *newl;
	int maxline = INIT_MAXLINE;
	char *line = (char *) malloc(maxline);

	/*Controllo che il file non sia vuoto*/
	if (line == NULL)
	{
		return NULL;
	}
	for (i = 0; (c=getc(fin))!=EOF && !endOfLine(fin,c); i++)
	{
		if (i >= maxline -1)
		{
			maxline *= 2;
			newl = (char *) realloc (line, maxline);
			/*Faccio questo controllo perché ho appena allocato memoria 
			  quindi necessito di una verifica sull'effettiva allocazione
			  della stessa*/
			if (newl == NULL)
			{
				/*Se ho fallito libero line*/
				free(line);
				return NULL;
			}
			line = newl;
		}
		line[i] = c;
	}
	line[i]= '\0';
	/*Fine del file, ho EOF all'inizio della riga*/
	if (c == EOF && i == 0)
	{
		free(line);
		return NULL;
	}
	else
		return line;
}