#encoding "utf-8"
#include <drinking.cxx>
#GRAMMAR_ROOT S

S -> Who<sp-agr[1],gram='anim'> interp (Drinking.Who) AnyWord* Consuming<sp-agr[1]> interp (Drinking.Consuming) Someword* Drink<gram='acc'> interp (Drinking.Drink);

Who -> Noun | Word<gram="SPRO">;
Drink -> Noun<kwtype=alco> ;
Consuming -> Verb ;
Someword -> Noun | Adj | Adv | OrdinalNumeral | Participle | Prep | Verb<gram="partcp"> | Verb<gram="ger"> | Comma | Hyphen | LBracket | RBracket | QuoteDbl | Word<gram="CONJ"> | Word<gram="INTJ"> | Word<gram="PART"> |  Word<gram="PR">;