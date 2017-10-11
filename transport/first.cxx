#encoding "utf8"
#GRAMMAR_ROOT S

MotionVerb -> Verb<kwtype='глаголы_передвижения'>;
MotionPrepAbl -> 'в' | 'во' | 'на';
MotionPrepDat -> 'к' | 'ко';
MotionTarget -> MotionPrepAbl Adj<c-agr[2]>* Noun<gram='вин', c-agr[2]>;
MotionTarget -> MotionPrepDat Adj<c-agr[2]>* Noun<gram='дат', c-agr[2]>;

Subject -> Adj<gram='им', c-agr[1]>* AnyWord<c-agr[1]>;
ProperName -> Noun<h-reg1>+;
Subject -> ProperName;

TargetedMotion -> Subject MotionVerb AnyWord* MotionTarget;

TransportUnit -> Noun<kwtype='транспорт'>;
MechTransportVerb -> 'ехать' | 'останавливаться' | 'мчаться' | 'подъезжать' | 'стучать' | 'поехать';
TransportMovement -> (AnyWord) (AnyWord) (AnyWord) (AnyWord) TransportUnit Adv* Adj* MotionVerb (MotionTarget);


// S -> TargetedMotionAbl | TargetedMotionDat;

S -> TransportMovement;