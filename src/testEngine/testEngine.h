// Begin testEngine.h
#ifndef QTESTENGINE_H
#define QTESTENGINE_H 1

class TestEngine {
    public:
        TestEngine();
        ~TestEngine();

        // Admin/teacher/ creates specific challange
        // [*] testInfo:
        //      > testType   - area of knowledge (education|psychology|funny)
        //      > section    - name of discipline or knowledge area
        //      > subsection - subsection of discipline or knowledge area
        void createChallenge();

        // section
        // subsection
        void runSession();


};



#endif
// End testEngine.h
