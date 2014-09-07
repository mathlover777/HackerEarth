#include <iostream>
#include <queue>

using namespace std;

int main ()
{
    queue <string> names; /* Declare a queue */
    names.push ("Danny"); /* Add some values to the queue */
    names.push ("Kayleigh"); /* Much like vectors */
    names.push ("Joe"); /* This basically does the same thing */

    cout << "There are currently " << names.size () << " people in the queue" << endl
         << "The person at the front of the queue is " << names.front () << endl
         << "The person at the back of the queue is " << names.back () << endl << endl;

    cout << names.front () << " has been served!" << endl;
    names.pop ();
    cout << "There are currently " << names.size () << " people in the queue" << endl
         << "The person at the front of the queue is " << names.front () << endl
         << names.back () << " is still at the back!" << endl;
    cin.get ();
    return 0;
}
