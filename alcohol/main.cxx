#encoding "utf-8"
#include <drinking.cxx>
#GRAMMAR_ROOT S

S -> Who<sp-agr[1]> interp (Drinking.Who) AnyWord* Consuming<sp-agr[1]> interp (Drinking.Consuming) Someword* Drink<gram='acc'> interp (Drinking.Drink);

Who -> Noun<gram='anim'> | Word<gram="SPRO"> | Word<gram="APRO">;
Drink -> Noun<kwtype=alco> ;
Consuming -> Verb ;
Someword -> Noun | Adj | Adv | OrdinalNumeral | Participle | Prep | Verb<gram="partcp"> | Verb<gram="ger"> | Comma | Hyphen | LBracket | RBracket | QuoteDbl | Word<gram="CONJ"> | Word<gram="INTJ"> | Word<gram="PART"> |  Word<gram="PR">;


S -> Noun<kwtype=situ> interp (PassiveDrinking.Situation);

AdjWord -> Adj | SimConjAnd | Comma;
S -> Adj<gnc-agr[2], kwtype=persadj> interp (DrankPerson.How) AdjWord* Noun<gnc-agr[2]>* interp (DrankPerson.Who) ;

DrVerb -> Verb<kwtype=drverbs>;
SDrVerb -> Verb<kwtype=sdrverbs>;
S -> Who<sp-agr[1],gram='anim'>* interp (VerbDrinking.Who) AnyWord* DrVerb<sp-agr[1],gram="intr"> interp (VerbDrinking.Consuming);
S -> Who<sp-agr[1],gram='anim'>* interp (VerbDrinking.Who) AnyWord* DrVerb<sp-agr[1],gram="tran"> interp (VerbDrinking.Consuming) Someword* Noun<gram='acc'> interp (VerbDrinking.Drink);
S -> Who<sp-agr[1],gram='anim'>* interp (VerbDrinking.Who) AnyWord* SDrVerb<sp-agr[1],gram="tran"> interp (VerbDrinking.Consuming) Someword* Drink<gram='acc'> interp (VerbDrinking.Drink);
S -> Noun<kwtype="емкость"> interp (VesselOfLiquid.Vess) AdjWord* Noun<gram="gen">* interp (VesselOfLiquid.Drink) ;
