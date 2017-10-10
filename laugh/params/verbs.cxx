#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S      // указываем корневой нетерминал грамматики

ProperName ->  Word<h-reg1>+; 
Person -> ProperName | 'человек'; 
FormOfAddress -> 'товарищ' | 'мистер' | 'господин';   // перечисление возможных форм обращения

LaughVerbs -> 'смеяться' | 'усмехнуться' | 'хохотать' |
			'хихикать' | 'гоготать' | 'ржать' | 
			'грохотать' | 'кудахтать' | 'прыснуть' |
			'улыбаться' | 'ухмыляться' | 'осклабиться';
					 

S ->  Person LaughVerbs;    