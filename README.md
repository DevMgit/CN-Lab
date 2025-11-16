# Networking & Cryptography Algorithms — Descriptions
## Sliding Window Protocol

Sliding Window Protocol is a core flow-control and reliability mechanism used in data-link communication, allowing multiple frames to be transmitted before acknowledgments return. Instead of sending one frame at a time, the sender maintains a window of frames it is permitted to transmit, while the receiver maintains a window of frames it is willing to accept. This improves efficiency by keeping the channel busy. Stop-and-Wait is the simplest form with a window size of 1, Go-Back-N allows continuous transmission but retransmits all frames from the first lost one, and Selective Repeat further optimizes recovery by retransmitting only the lost frames while accepting out-of-order ones. These strategies balance performance, complexity, and reliability in modern data-link communication.

## Distance Vector Routing

Distance Vector Routing is a distributed routing method where each router periodically exchanges routing information with its neighbors. Each router maintains a table of the shortest known distances to all destinations and updates these distances using the Bellman–Ford algorithm. Over time, routers converge to the best paths without needing full topology knowledge. While DVR is simple and easy to deploy, it can suffer from slow convergence and routing loops, addressed by techniques like split horizon, route poisoning, and hold-down timers. DVR underpins protocols such as RIP and remains foundational in understanding adaptive routing behavior in networks.

## Dijkstra’s Shortest Path Algorithm

Dijkstra’s Algorithm finds the minimum-cost routes from a single source to all other nodes in a weighted graph. It works by maintaining a set of permanently selected nodes whose shortest paths are known, and a set of nodes still being evaluated. At each step, the algorithm picks the nearest unvisited node, updates (relaxes) its neighbors, and repeats until all nodes are processed. Because it never revisits nodes and always chooses the smallest tentative distance, it guarantees optimal paths for graphs with non-negative weights. This algorithm forms the backbone of routing decisions in high-performance networks and operating systems.

## Link State Routing

Link State Routing gives each router a complete and synchronized view of the network topology through link-state advertisements (LSAs) that are flooded across all routers. Every router independently builds a link-state database (LSDB), representing the full graph of nodes and link costs. Using this database, each router runs Dijkstra’s algorithm to compute shortest paths. This results in fast convergence, loop-free routing, and highly stable behavior even in large and dynamic networks. Protocols like OSPF and IS-IS use link-state principles to provide robust, scalable routing essential in enterprise and backbone networks.

## Caesar Cipher Encryption

The Caesar Cipher is one of the oldest and simplest symmetric-key encryption techniques, shifting each letter of the plaintext by a fixed number of positions in the alphabet. Encryption replaces each character with its shifted counterpart, while decryption reverses the shift. Though insecure by modern cryptographic standards due to its small keyspace, it clearly demonstrates substitution ciphers, modular arithmetic, and the core idea of reversible transformations using shared keys. It remains an important educational tool and a gateway to understanding more advanced encryption methods.

## Leaky Bucket Algorithm

The Leaky Bucket Algorithm controls the rate of outgoing traffic by placing incoming packets into a fixed-capacity bucket and allowing them to exit at a steady, predetermined rate. If traffic bursts exceed the bucket’s remaining capacity, excess packets are discarded, thereby smoothing network traffic and preventing congestion. This method is widely applied in traffic shaping, QoS management, and congestion control in routers and switches. By enforcing predictable output regardless of bursty input, it supports fairness, stability, and efficient bandwidth utilization across network flows.
