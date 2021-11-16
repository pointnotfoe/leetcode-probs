/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/robot-bounded-in-circle/submissions/
*/

/*
On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degrees to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

Constraints:

1 <= instructions.length <= 100
instructions[i] is 'G', 'L' or, 'R'.
*/
class Solution {
public:
    void run_robot(string instructions, 
                   int &x, int &y, int &dx, int &dy,
                   int &total_x, int &total_y)
    {
        for (int j = 0; j < instructions.size(); j++)
        {
            if (instructions[j] == 'G')
            {
                x += dx;
                y += dy;
                total_x += abs(dx);
                total_y += abs(dy);
                //radius
            }
            else 
            {
                if (dy == 1)
                {
                    dy = 0;
                    if (instructions[j] == 'R')
                    {
                        dx = 1;
                    }
                    else
                    {
                        dx = -1;
                    }
                }
                else if (dy == -1)
                {
                    dy = 0;
                    dx = -1;                        
                    if (instructions[j] == 'R')
                    {
                        dx = -1;
                    }
                    else
                    {
                        dx = 1;
                    }
                }
                else
                {
                    if (dx == 1)
                    { 
                        if (instructions[j] == 'R')
                        {
                            dy = -1;
                        }
                        else
                        {
                            dy = 1;
                        }
                        dx = 0;
                    }
                    else if (dx == -1)
                    {                            
                        if (instructions[j] == 'R')
                        {
                            dy = 1;
                        }
                        else
                        {
                            dy = -1;
                        }
                        dx = 0;
                    }
                }
            }

        }
    }//run_robot
    
    bool isRobotBounded(string instructions) //mine
    {
        //just go command
        if ((string::npos == instructions.find('R')) && 
            (string::npos == instructions.find('L')))
        {
            return false;
        }
        //just turn left or right command
        if (string::npos == instructions.find('G'))
            //(instructions.size() == 1 && instructions[0] != 'G')//strncmp(command,"G")
        {
            return true;
        }
        //else
        
        int x = 0, y = 0, dx = 0, dy = 1;// start from origin facing up
        int total_x = 0, total_y = 0;
        run_robot(instructions, x, y, dx, dy, total_x, total_y);
        cout << "x = " << x<< ", y = " << y << ", dx = " << dx<< ", dy = " << dy <<endl; 
        cout << "total_x = " << total_x<< ", total_y = " << total_y<<endl;
       /* if (dy == 0)
        {
            int xp = x, yp = y, dxp = dx, dyp = dy;
            run_robot(instructions, xp, yp, dxp, dyp);
            if (x == xp && y == yp)
            {
                return true;
            }
            else 
            {
                return false;
            }


        }*/
        if (total_x == 0 || total_y == 0)//only moved along one of the axis
        {
            return true;
        }
        if (dy == 1) 
        {    
            if ((x == 0) && (y == 0))//back where started
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (dy == 0)
        {
            return true;
        }
        else//dy == -1
        {
            //if (total_x == total_y)
            return false;
        }
    }
	//solution: https://leetcode.com/problems/robot-bounded-in-circle/discuss/290856/JavaC%2B%2BPython-Let-Chopper-Help-Explain
		/*https://leetcode.com/problems/robot-bounded-in-circle/discuss/290856/JavaC++Python-Let-Chopper-Help-Explain/275582
		Try to prove with math representation:
	Let's say the robot starts with facing up. It moves [dx, dy] by executing the instructions once.
	If the robot starts with facing
	right, it moves [dy, -dx];
	left, it moves [-dy, dx];
	down, it moves [-dx, -dy]

	If the robot faces right (clockwise 90 degree) after executing the instructions once,
	the direction sequence of executing the instructions repeatedly will be up -> right -> down -> left -> up
	The resulting move is [dx, dy] + [dy, -dx] + [-dx, -dy] + [-dy, dx] = [0, 0] (back to the original starting point)

	All other possible direction sequences:
	up -> left -> down -> right -> up. The resulting move is [dx, dy] + [-dy, dx] + [-dx, -dy] + [dy, -dx] = [0, 0]
	up -> down -> up. The resulting move is [dx, dy] + [-dx, -dy] = [0, 0]
	up -> up. The resulting move is [dx, dy]
	*/
	bool isRobotBounded(string instructions) {//lee215
        int x = 0, y = 0, i = 0;
        vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        for (char & ins : instructions)
            if (ins == 'R')
                i = (i + 1) % 4;
            else if (ins == 'L')
                i = (i + 3) % 4;
            else
                x += d[i][0], y += d[i][1];
        return x == 0 && y == 0 || i > 0;
    }
};

int main()
{
	{
		string instructions = "GG";
		bool result = isRobotBounded(instructions);
		assert(false == result);
	}
	
	{
		string instructions = "GL";
		bool result = isRobotBounded(instructions);
		assert(true == result);
	}
	
	{
		string instructions = "GGLLGG";
		bool result = isRobotBounded(instructions);
		assert(true == result);
	}
	
	{
		string instructions = "GLGLGGLGL";
		bool result = isRobotBounded(instructions);
		assert(false == result);
	}
	
	{
		string instructions = "RLLGLRRRRGGRRRGLLRRR";
		bool result = isRobotBounded(instructions);
		assert(true == result);
	}
	

    return 0;

}