/**
 * A demo program for bull-pgia.
 * 
 * @author Carmel-Efrat-Odelia
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int wrong=0;
	int right=0;

	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}

		// our tests
		ConstantChooser a1111{"1111"}, a3452{"3452"}, a4567{"4567"};
		ConstantGuesser b1111{"1111"}, b3452{"3452"}, b4567{"4567"};
    
		ConstantChooser e1998{"1998"}, e2039{"2039"}, e5641{"5641"};
	  ConstantGuesser f1998{"1998"}, f2039{"2039"}, f5641{"5641"};

    ConstantChooser s56565{"56565"}, s8787{"8787"}, s367878{"367878"},s0909090("0909090");
	  ConstantGuesser d9434{"9434"}, d2222{"2222"}, d232323{"232323"},d50699("50699");

		ConstantChooser s{""}, s000000{"000000"}, s202020{"202020"},s872315("872315");
	  ConstantGuesser d{""}, d000000{"000000"}, d202020{"202020"},d787878("787878");

    ConstantChooser s1{"1"}, s4{"4"}, s2{"2"},s6("6");
	  ConstantGuesser d2{"2"}, d6{"6"}, d4{"4"},d8("8");

    ConstantChooser p00{"00"}, p23{"23"}, p54{"54"},p87("87");
	  ConstantGuesser x77{"77"}, x12{"12"}, x60{"60"},x56("56");

    ConstantChooser h222{"222"}, h201{"201"}, h555{"555"},h777("777");
	  ConstantGuesser k333{"333"}, k666{"666"}, k444{"444"},k765("765");

    ConstantChooser j40404040{"40404040"}, j13567{"13567"}, j890098{"890098"},j777("6758");
	  ConstantGuesser m12354{"12354"}, m300000{"300000"}, m890098{"890098"},m3498("3498");

    ConstantChooser i12345{"12345"}, i3498{"3498"}, i700000{"700000"},i7767("7767");
	  ConstantGuesser n23{"23"}, n201{"201"}, n5{"5"},n13567("13567");

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1111","1111"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1998","8199"), "1,3")      // 1 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3452","4352"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1998","8199"), "1,3")      // 1 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2093","2093"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("5641","4651"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("000000","000000"), "6,0")      // 6 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("202020","202002"), "4,2")      // 4 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("18","78"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("90","20"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("777","877"), "2,0")    // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("548","238"), "1,0")    // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("55","66"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("55","23"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234567","1030507"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("6565656565","5656565656"), "0,10")      // 0 bull, 10 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("888888888","888888888"), "9,0")      // 9 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("4564564564","4564564568"), "9,0")      // 9 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3948576","3948501"), "5,0")   // 5 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("66666666","61616161"), "4,0")    // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("548","238"), "1,0")    // 1 bull, 0 pgia
		
    
		;

		testcase.setname("Calculate bull and pgia - Error: Invalid input or Unequal string length")
		.CHECK_THROWS (calculateBullAndPgia("","")) 
		.CHECK_THROWS(calculateBullAndPgia("111","1093")) 
		.CHECK_THROWS(calculateBullAndPgia("abc","bca"))
		.CHECK_THROWS(calculateBullAndPgia("/*","#&"))
		.CHECK_THROWS(calculateBullAndPgia("-5","-5"))
		.CHECK_THROWS(calculateBullAndPgia("3212","54")) 
		.CHECK_THROWS(calculateBullAndPgia("1000000","100000000"))
		.CHECK_THROWS(calculateBullAndPgia("3212","54"))
		                 

		;



		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(a1111, b1111, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(s202020,d202020,6, 100), 1)    //guesser wins in one turn. 
		.CHECK_EQUAL(play(e1998,f2039, 4, 5), 6)   //  guesser loses by running out of turns.
		.CHECK_EQUAL(play(s, d000000, 0, 2), 3)     // guesser loses technically by choosing an illegal number (too long).
     
		 .CHECK_EQUAL(play(e5641, d2222, 4, 100), 101)      // guesser loses by running out of turns.
		.CHECK_EQUAL(play(s2, k444, 1, 15), 16)    // guesser loses by running 
		.CHECK_EQUAL(play(s872315,b4567, 6, 3), 4)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(a3452, d787878, 4, 12),13)     // guesser loses technically by choosing an illegal number (too long).
		
	
	.CHECK_EQUAL(play(j13567,n13567, 5, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(i700000, d000000, 6, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(e5641, m300000, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(a4567, f1998, 4, 100), 101)     // guesser loses by running out of turns 
	
		
		.CHECK_EQUAL(play(h201, n201, 3, 100), 1)    // guesser wins in one turn.
		.CHECK_EQUAL(play(i3498, x56, 4, 100), 101)   // guesser loses technically by making an illegal guess (too short).
		.CHECK_EQUAL(play(j40404040, k666, 3, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
	
		.CHECK_EQUAL(play(s0909090, m300000, 7, 100), 101)      // guesser loses technically by making an illegal guess (too short).
		.CHECK_EQUAL(play(p23, x60, 2, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(e5641, n5, 4, 9), 10)   // guesser loses technically by making an illegal guess (too short).
		.CHECK_EQUAL(play(j890098, k765, 3, 16), 0)     // chooser loses technically by choosing an illegal number (too long).

    .CHECK_EQUAL(play(p00, g1234, 2, 1), 2)      // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(h222, k333, 3, 1), 2)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(p00, g12345, 2, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(p54, x60, 2, 3), 4)     // guesser loses by running out of turns ..
	
		.CHECK_EQUAL(play(s2, d2, 1, 3), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(p87,x77, 2, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(a4567,k765, 4, 8), 9)   // guesser loses technically by making an illegal guess (too short).
		.CHECK_EQUAL(play(e2039,g1234, 4, 100), 101)     //guesser loses by running out of turns .
	
	;

	testcase.setname("Play with dummy choosers and guessers - Error ")
  .CHECK_THROWS(play(s, d, 0, 100))

	;


	testcase.setname("Play with smart guesser");

		RandomChooser daniel;
		SmartGuesser shira;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(daniel, shira, 3, 100)<=100,true);  // smarty should always win in at most 100 turns!
		}

		RandomChooser shir;
		SmartGuesser kali;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(shir, kali, 2, 100)<=100, true);  // smarty should always win in at most 100 turns!
		}
		;

    grade = testcase.grade();
		wrong= testcase.wrong();
		right=testcase.right();

	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout <<"Your grade is: "  << grade << " "<< "Wrong: " << wrong<< "  " << "Right: " << right <<" " <<  endl;
	return 0;
}
