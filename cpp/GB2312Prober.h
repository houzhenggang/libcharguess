/*
	libcharguess	-	Guess the encoding/charset of a string
    Copyright (C) 2003  Stephane Corbe <noubi@users.sourceforge.net>
	Based on Mozilla sources

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef GB2312Prober_h__
#define GB2312Prober_h__

#include "charsetProber.h"
#include "codingStateMachine.h"
#include "charDistribution.h"

// We use gb18030 to replace gb2312, because 18030 is a superset. 

class GB18030Prober: public CharSetProber {
public:
  GB18030Prober(void){mCodingSM = new CodingStateMachine(&GB18030SMModel);
                      Reset();};
  virtual ~GB18030Prober(void){delete mCodingSM;};
  ProbingState HandleData(const char* aBuf, PRUint32 aLen);
  const char* GetCharSetName() {return "gb18030";};
  ProbingState GetState(void) {return mState;};
  void      Reset(void);
  float     GetConfidence(void);
  void      SetOpion() {};

protected:
  void      GetDistribution(PRUint32 aCharLen, const char* aStr);
  
  CodingStateMachine* mCodingSM;
  ProbingState mState;

  //GB2312ContextAnalysis mContextAnalyser;
  GB2312DistributionAnalysis mDistributionAnalyser;
  char mLastChar[2];

};


#endif /* GB2312Prober_h__ */
