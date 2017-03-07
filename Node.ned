//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package oppo_aodv;
simple Node
{
    gates:
        inout g[];
}
//
// 
//
network Node3test
{
    types:
        channel Channel extends ned.DelayChannel
        {
            delay = 100ms;
        }
    submodules:
        Node[4]: Node;
    connections:
        Node[0].g++ <--> Channel <--> Node[1].g++;
        
        Node[0].g++ <--> Channel <--> Node[2].g++;
        Node[0].g++ <--> Channel <--> Node[3].g++;
        Node[1].g++ <--> Channel <--> Node[2].g++;
        Node[1].g++ <--> Channel <--> Node[3].g++;
        Node[2].g++ <--> Channel <--> Node[3].g++;
}
