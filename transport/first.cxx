#encoding "utf8"
#GRAMMAR_ROOT S

MeansOfTransport -> 'трамвай' | 'автомобиль' | 'машина';
MotionVerb -> 'идти' | 'бежать' | 'броситься' | 'двинуть' | 'ползти' | 
              'приближаться' | 'кидать' | 'бросать' | 'вести';
TargetPrep -> 'до' | 'к' | 'ко' | 'в' | 'на';
OriginPrep -> 'от' | 'из' | 'с';

NounOrPronoun -> Noun | Pronoun;

TargetedMotion -> Adj<gram='им', c-agr[1]>* NounOrPronoun<c-agr[1]>* 
                  Adv* MotionVerb AnyWord* TargetPrep Adj<c-agr[2]>* Noun<gram='пр', c-agr[2]>;

S -> TargetedMotion;