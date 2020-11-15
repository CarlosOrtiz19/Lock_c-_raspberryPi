//
// Created by carlos on 11/14/20.
//

#ifndef TP2_MOCK_INPUTCALLBACK_H
#define TP2_MOCK_INPUTCALLBACK_H


class InputCallBack {

private:
    //not sure si here
    int previousState{LOW};
    int actualState{LOW};

public:
    InputCallBack();
    bool operator()(bool state);



};


#endif //TP2_MOCK_INPUTCALLBACK_H
