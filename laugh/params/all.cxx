#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S      // указываем корневой нетерминал грамматики

ProperName ->  Word<h-reg1>+;                  
Person -> ProperName | 'человек'; 
FormOfAddress -> 'товарищ' | 'мистер' | 'господин';   // перечисление возможных форм обращения


LaughNouns -> 'смех' | 'хохот' | 'гогот' | 'смешок' 
					 | 'шутка' | 'веселье' | 'хихиканье';	

LaughVerbs -> 'смеяться' | 'усмехнуться' | 'хохотать' |
			'хихикать' | 'гоготать' | 'ржать' | 
			'грохотать' | 'кудахтать' | 'прыснуть';				

// существительные
S ->  Adj+ LaughNouns;  
S ->  Verb LaughNouns;  
S ->  Verb Adj+ LaughNouns;

S ->  Person Verb LaughNouns;    
S ->  Person Verb Adj+ LaughNouns;    


// глаголы
S ->  Person LaughVerbs;  
S ->  Noun LaughVerbs;  
// над чем
S ->  Person LaughVerbs Prep Noun;  
S ->  Noun LaughVerbs Prep Noun;  

// как  
S ->  Person Adv LaughVerbs;  
S ->  Noun Adv LaughVerbs;   


