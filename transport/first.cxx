#encoding "utf8"
#GRAMMAR_ROOT S

MeansOfTransport -> 'трамвай' | 'автомобиль' | 'машина';
MotionVerb -> 'идти' | 'бежать' | 'броситься' | 'двинуть' | 'ползти' | 
              'приближаться' | 'кидать' | 'бросать' | 'вести';
TargetPrep -> 'до' | 'к' | 'ко' | 'в';

GeneralMotion -> Noun+ MotionVerb;
TargetedMotion -> Adj<gram='им'>* Noun* MotionVerb AnyWord* TargetPrep Adj* Noun<gram='пр'>;

S -> GeneralMotion;