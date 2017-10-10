#encoding "utf-8"
#include <drinking.cxx>
#GRAMMAR_ROOT S

S -> Who<sp-agr[1]> interp (Drinking.Who) AnyWord* Consuming<sp-agr[1]> interp (Drinking.Consuming) AnyWord* Drink<gram='acc'> interp (Drinking.Drink);

Who -> Noun<kwtype=pers> ;
Drink -> Noun<kwtype=alco> ;
Consuming -> Verb ;
