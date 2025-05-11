#include<iostream>
#include <queue>

using namespace std;

struct Pemesan {
    string nama;
    int idKategori;
    string kategori;
};

// Linked List
struct Node {
    Pemesan data;
    Node* next;
};

// Tree
struct NodeTree {
    int id;
    string namaKategori;
    NodeTree* left;
    NodeTree* right;
};

class Tiket {
    private:
        Node* head;
        queue<Pemesan> antrianPesanan;
        NodeTree* root;

        NodeTree* insert(NodeTree* node, int id, string nama) {
            if (!node) {
                node = new NodeTree();
                node->id = id;
                node->namaKategori = nama;
                node->left = node->right = nullptr;
                return node;
            }
            if (id < node->id)
                node->left = insert(node->left, id, nama);
            else if (id > node->id)
                node->right = insert(node->right, id, nama);
            return node;
        }
        
        void inorder(NodeTree* node) {
            if (node) {
                inorder(node->left);
                cout << "ID: " << node->id << ", Kategori: " << node->namaKategori << endl;
                inorder(node->right);
            }
        }

        NodeTree* cariKategori(NodeTree* node, int id) {
            if (!node)
                return nullptr;
            if (node->id == id)
                return node;
            if (id < node->id)
                return cariKategori(node->left, id);
            else
                return cariKategori(node->right, id);
        }
        
        
    public:
        Tiket() : head(nullptr), root(nullptr) {}
        
        void pesan(Pemesan p) {
            Node* newNode = new Node();
            newNode->data = p;
            newNode->next = nullptr;
    
            if (!head) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next)
                    temp = temp->next;
                temp->next = newNode;
            }
            
            // add to queue
            antrianPesanan.push(p);
            cout << "Pemesan " << p.nama << " ditambahkan ke daftar.\n";
        }
        
        void tampilkanPesanan() {
            Node* temp = head;
            if (!temp) {
                cout << "Belum ada pemesan.\n";
                return;
            }
            cout << "\n=== Daftar Pemesan ===\n";
            while (temp) {
                cout << "Nama: " << temp->data.nama 
                     << ", Kategori: " << temp->data.kategori << endl;
                temp = temp->next;
            }
        }
        
        void tambahKategori(int id, string nama, int parentId) {
            NodeTree* parentNode = getKategori(parentId);
            if (!parentNode) {
                root = insert(root, id, nama);
                cout << "Kategori ID:" << id << ", Nama:" << nama << " ditambahkan sebagai root.\n";
            } else {
                insert(parentNode, id, nama);
                cout << "Kategori ID:" << id << ", Nama:" << nama << " ditambahkan ke parent root: " << parentNode->namaKategori << "\n";
            }
        }
    
        void tampilkanKategori() {
            cout << "\n=== Kategori Tiket ===\n";
            inorder(root);
        }
    
        NodeTree* getKategori(int id) {
            return cariKategori(root, id);
        }
        
        void ambilAntrian() {
            if (!antrianPesanan.empty()) {
                Pemesan p = antrianPesanan.front();
                cout << "Ambil Antrian, Nama: " << p.nama 
                     << ", Kategori: " << p.kategori << endl;
                antrianPesanan.pop();
            } else {
                cout << "Antrian kosong, tidak ada pesanan.\n";
            }
        }
        
        void tampilkanAntrian() {
            cout << "\n=== Jumlah Antrian ===\n";
            cout << antrianPesanan.size() << "\n";
        }
};

int main()
{
    Tiket tiket;
    tiket.tambahKategori(101, "VIP", 0);
    int pilihan;
    do {
        cout << "\n=== APLIKASI PEMESANAN TIKET ===\n";
        cout << "1. Tambah Pemesan\n";
        cout << "2. Tampilkan Daftar Pemesan\n";
        cout << "3. Ambil Antrian\n";
        cout << "4. Tampilkan Antrian\n";
        cout << "5. Tambah Kategori Tiket\n";
        cout << "6. Tampilkan Kategori Tiket\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: {
                Pemesan p;
                int idKategori;
                cout << "Masukkan Nama: ";
                cin >> ws; getline(cin, p.nama);
                cout << "Masukkan ID Kategori: ";
                cin >> idKategori;
                p.idKategori = idKategori;
                NodeTree* c = tiket.getKategori(idKategori);
                if (!c) {
                    cout << "Kategori tidak ditemukan!\n";
                    break;
                }
                p.kategori = c->namaKategori;
                tiket.pesan(p);
                break;
            }
            case 2:
                tiket.tampilkanPesanan();
                break;
            case 3:
                tiket.ambilAntrian();
                break;
            case 4:
                tiket.tampilkanAntrian();
                break;
            case 5: {
                int idKategori, idParentKategori;
                string kategori;
                cout << "Masukkan ID Kategori: ";
                cin >> idKategori;
                cout << "Masukkan Nama: ";
                cin >> kategori;
                cout << "Masukkan Parent ID: ";
                cin >> idParentKategori;
                tiket.tambahKategori(idKategori, kategori, idParentKategori);
                break;
            }
            case 6:
                tiket.tampilkanKategori();
                break;
            case 0:
                cout << "Keluar dari aplikasi.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
    return 0;
}
