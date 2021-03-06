/*Nonogram solver */

typedef struct {
    int nPoint;
    int* pLen;
} hint;

typedef struct {
    int nrow;
    int ncol;
} size2D;

typedef struct {
    int **map; //[row][col]
    int size2D;
    hint* hints;
} nogram;


nogram init_nogram(size2D);
void close_nogram(nogram);