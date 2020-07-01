/* MyMEXFunction
 * Adds second input to each  
 * element of first input
 * a = MyMEXFunction(a,b);
*/

#include "mex.hpp"
#include "mexAdapter.hpp"
#include "bat_bioacoustics.h"

using namespace matlab::data;
using matlab::mex::ArgumentList;

class MexFunction : public matlab::mex::Function {
public:
    void operator()(ArgumentList outputs, ArgumentList inputs) {

        // Validate arguments
        //checkArguments(outputs, inputs);
		ArrayType type = inputs[0].getType();
        TypedArray<int16_t> m = inputs[0];
        std::vector<int> in1(m.begin(), m.end());
        std::size_t in2 = inputs[1][0];
        std::size_t in3 = inputs[2][0];
        double in4 = inputs[3][0];
        double in5 = inputs[4][0];
        double in6 = inputs[5][0];
        double in7 = inputs[6][0];
        double in8 = inputs[7][0];
        std::size_t in9 = inputs[8][0];
        std::size_t in10 = inputs[9][0];
        double in11 = inputs[10][0];
        double in12 = inputs[11][0];
        double in13 = inputs[12][0];
        std::size_t in14 = inputs[13][0];
        double in15 = inputs[14][0];
        double in16 = inputs[15][0];
        double in17 = inputs[16][0];
        const std::size_t in18 = inputs[17][0];
        double in19 = inputs[18][0];
        double in20 = inputs[19][0];
        
        StructArray result = threshold_detection_impl(in1,in2,in3,in4,in5,
                in6,in7,in8,in9,in10,in11,in12,in13,in14,in15,in16,in17,
                in18,in19,in20);
        
        outputs[0] = result;
    }
    
    void checkArguments(ArgumentList outputs, ArgumentList inputs) {
        std::shared_ptr<matlab::engine::MATLABEngine> matlabPtr = getEngine();
        ArrayFactory factory;
        if (inputs[0].getType() != ArrayType::DOUBLE ||
            inputs[0].getType() == ArrayType::COMPLEX_DOUBLE)
        {
            matlabPtr->feval(u"error", 0, 
                std::vector<Array>({ factory.createScalar("Input must be double array") }));
        }

        if (outputs.size() > 1) {
            matlabPtr->feval(u"error", 0, 
                std::vector<Array>({ factory.createScalar("Only one output is returned") }));
        }
    }
        
};