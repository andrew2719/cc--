import hashlib
import time

class Block:
    def __init__(self, index, data, previous_hash):
        self.index = index
        self.timestamp = time.time()
        self.data = data
        self.previous_hash = previous_hash
        self.nonce = 0
        self.hash = self.calculate_hash()

    def calculate_hash(self):
        return hashlib.sha256(str(self.index).encode('utf-8') +
                              str(self.timestamp).encode('utf-8') +
                              str(self.data).encode('utf-8') +
                              str(self.previous_hash).encode('utf-8') +
                              str(self.nonce).encode('utf-8')).hexdigest()

    def mine_block(self, difficulty):
        while self.hash[:difficulty] != '0' * difficulty:
            self.nonce += 1
            self.hash = self.calculate_hash()

        print('Block mined:', self.hash)

class Blockchain:
    def __init__(self):
        self.chain = [self.create_genesis_block()]
        self.difficulty = 5

    def create_genesis_block(self):
        return Block(0, 'Genesis Block', '0')

    def get_latest_block(self):
        return self.chain[-1]

    def add_block(self, new_block):
        new_block.previous_hash = self.get_latest_block().hash
        new_block.mine_block(self.difficulty)
        self.chain.append(new_block)

    def is_chain_valid(self):
        for i in range(1, len(self.chain)):
            current_block = self.chain[i]
            previous_block = self.chain[i-1]

            if current_block.hash != current_block.calculate_hash():
                return False

            if current_block.previous_hash != previous_block.hash:
                return False

        return True

# create a new blockchain
blockchain = Blockchain()

# add some blocks to the chain
blockchain.add_block(Block(1, 'Block 1', ''))
blockchain.add_block(Block(2, 'Block 2', ''))
blockchain.add_block(Block(3, 'Block 3', ''))

# print the blockchain
for block in blockchain.chain:
    print(vars(block))

# check if the chain is valid
print('Is the blockchain valid?', blockchain.is_chain_valid())
