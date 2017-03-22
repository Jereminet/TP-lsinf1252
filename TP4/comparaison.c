typedef struct {
    int numerateur;
    int denominateur;
} fraction_t;

int fraction_compare(const void * a, const void * b){
	int premier = (a->numerateur/a->denominateur);
	int deuxieme = (b->numerateur/b->denominateur);
	return premier-deuxieme;
}
