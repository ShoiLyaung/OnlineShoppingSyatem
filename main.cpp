#include <bits/stdc++.h>
using namespace std;

string seller_code;
template<typename T>
struct List {
//定义节点结构体
    struct Node {
        string code,name;
        T data;
        Node *next;
    };
    Node *head;
//通过构造函数初始化列表
    List() {
        head = nullptr;
    }
//1. 查询节点
    Node *Search_by_code(string &search_code) {
        Node *ptr = head;
        if (!ptr)  //链表为空，直接返回
        {
            return nullptr;
        } else {
//判断是否为查找节点
            while (ptr) {
                if (search_code == ptr->code) {
                    return ptr;
                }
                ptr = ptr->next;
            }
            return nullptr;
        }
    }
    Node *Search_by_name(string &search_name) {
        Node *ptr = head;
        if (!ptr)  //链表为空，直接返回
        {
            return nullptr;
        } else {
//判断是否为查找节点
            while (ptr) {
                if (search_name == ptr->name) {
                    return ptr;
                }
                ptr = ptr->next;
            }
            return nullptr;
        }
    }
//2. 显示节点
    void Display_Node(Node *ptr) {
        cout <<ptr->code <<' '<< ptr->name << endl;
    }
//3. 显示全部节点
    void Display_List() {
        Node *ptr = head;
        if (!ptr) {
            cout << "无节点" << endl;
            return;
        }
        cout << "全部节点信息：" << endl;
        while (ptr)    // 当指针head不空，则输出
        {
            cout <<ptr->code <<' '<< ptr->name << endl;
            ptr = ptr->next;
        }
    }
//4. 清空
    void Delete_List() {
        Node *ptr;
        while (head) {
            ptr = head;
            head = head->next;
            delete ptr;
        }
        cout << "列表已清空" << endl;
    }
//5. 增加节点
    void Add_Node(string &new_code) {
//定义变量
        struct Node *new_Node, *ptr, *ptr_next;
// 分配内存空间给新节点
        new_Node = new Node;
        new_Node->code = new_code;
        new_Node->next = nullptr;

        if (!head || new_Node->code <= head->code) {
            new_Node->next = head;
            head = new_Node;
            cout << "成功增加新成员：" << new_Node->code << endl;
            return;
        }
        ptr = head;
        ptr_next = head->next;
//新成员与head之后的成员比较
        while (ptr_next) {
            if (new_Node->code > ptr->code) {
                ptr = ptr_next;
                ptr_next = ptr_next->next;
            } else
                break;
        }
        ptr->next = new_Node;
        new_Node->next = ptr_next;
        cout << "成功增加新成员：" << new_Node->code << endl;
    }
//6. 删除节点
    void Delete_Node(Node *ptr) {
        Node *ptr_present = head, *ptr_next = nullptr;
        if (!head)  //链表为空，直接返回
        {
            cout << "无节点" << endl;
            return;
        } else {
            if (ptr == head)    //判断是否删除head成员
            {
                head = ptr->next;
                delete ptr;
                cout << "该节点已删除" << endl;
                return;
            }
            ptr_next = ptr_present->next;

            while (ptr_next && (ptr != ptr_next))    //判断是否删除head之后的成员
            {
                ptr_present = ptr_next;
                ptr_next = ptr_next->next;
            }
            if (ptr_next) {
                ptr_present->next = ptr_next->next;
                delete ptr_next;
                cout << "该节点已删除" << endl;
                return;
            }
            cout << "该节点不在名单中" << endl;
        }
    }
//7. 修改节点信息
    void Modify_Menu() {
        cout << "——————————————————————————" << endl
             << "|选择你要修改的信息：        |" << endl
             << "|1. 商品名称               |" << endl
             << "|2. 商品描述               |" << endl
             << "|3. 商品价格               |" << endl
             << "|4. 商品数量               |" << endl
             << "|q. 退出修改               |" << endl
             << "——————————————————————————" << endl;
    }
    void Modify_Node(Node *ptr) {
        if (ptr) {
            string modify_code,modify_name,modify_des;
            double modify_price;
            int modify_num;
            string con;
            Modify_Menu();
            while (1) {
                cin >> con;
                if (con.length() == 1) {
                    switch (con[0]) {
                        case '1':
                            cout << "你要将该商品的名称修改为：" << endl;
                            cin >> modify_name;
                            ptr->name=modify_name;
                            continue;
                        case '2':
                            cout << "你要将该商品的描述修改为：" << endl;
                            cin >> modify_des;
                            ptr->data.des=modify_des;
                            continue;
                        case '3':
                            cout << "你要将该商品的价格修改为：" << endl;
                            cin >> modify_price;
                            ptr->data.price=modify_price;
                            continue;
                        case '4':
                            cout << "你要将该商品的数量修改为：" << endl;
                            cin >> modify_num;
                            ptr->data.num=modify_num;
                            continue;
                        case 'm':
                            Modify_Menu();
                        case 'q':
                            return;
                        default:
                            cout << "输入错误，请重新选择" << endl;
                            Modify_Menu();
                            continue;
                    }
                }else{
                    cout << "输入错误，请重新选择" << endl;
                    Modify_Menu();
                    continue;
                }
            }
        }

    }
};
void refresh(string &code);
struct seller;
List<seller> sellers;
struct goods{   //商品编号、商品名称、商品描述、商品价格、商品件数、售卖商家编号(就一个)
    //
    string des;
    long double price;
    int num;
    seller* seller;
    string seller_code;
    void goods_init(){
        cout<<"请输入商品描述"<<endl;
        getline(cin,des);
        getline(cin,des);
        cout<<"请输入商品价格"<<endl;
        cin>>price;
        cout<<"请输入商品数量"<<endl;
        cin>>num;
        cout<<"成功添加商品"<<endl;
    }
//显示商品信息
    static void Display_goods(List<goods>::Node *ptr) {
        if(!ptr){
            cout << "无商品" << endl;
            return;
        }
        cout << endl;
        cout <<"商品编号："<< ptr->code << endl;
        cout <<"商品名称："<< ptr->name << endl;
        cout <<"商品描述："<< ptr->data.des << endl;
        cout <<"商品价格："<< ptr->data.price << endl;
        cout <<"商品数量："<< ptr->data.num << endl;
        cout <<"卖家编号："<< ptr->data.seller_code << endl;
    }
};
List<goods> sellers_goods;
struct buyer{   //买家编号、姓名、购买商品的编号(一个或者多个，多个以逗号分割)
    //浏览商品、购买商品的功能
    buyer(){

    }
    List<goods> buyer_goods;
    void Menu_Init(){
        cout << "————————————————————————————————" << endl
             << "|（1） 查询商品                   |" << endl
             << "|（2） 购买商品                   |" << endl
             << "|（m） 显示菜单                   |" << endl
             << "|（q） 退出                      |" << endl
             << "————————————————————————————————" << endl;
    }
    void search_goods(string search_name){
        List<goods>::Node *ptr = sellers_goods.head;
        while (ptr) {
            if (search_name == ptr->name) {
                ptr->data.Display_goods(ptr);
            }
            ptr = ptr->next;
        }
        return;
    }
    void buy_goods(List<goods>::Node *ptr,int num){
        if(!ptr){
            cout << "无商品" << endl;
            return;
        }
        if(!sellers.Search_by_code(sellers_goods.Search_by_code(ptr->code)->data.seller_code)){
            cout << "卖家已销户" << endl;
            return;
        }
        if(sellers_goods.Search_by_code(ptr->code)->data.num<num){
            cout << "商品货量不足" << " 商品货量仅剩：" <<sellers_goods.Search_by_code(ptr->code)->data.num<< endl;
            return;
        }
        if(!buyer_goods.Search_by_code(ptr->code))
        {
            buyer_goods.Add_Node(ptr->code);
            buyer_goods.Search_by_code(ptr->code)->name=ptr->name;
            buyer_goods.Search_by_code(ptr->code)->data.des=ptr->data.des;
            buyer_goods.Search_by_code(ptr->code)->data.price=ptr->data.price;
            buyer_goods.Search_by_code(ptr->code)->data.num=0;
            buyer_goods.Search_by_code(ptr->code)->data.seller_code=ptr->data.seller_code;
        }
        buyer_goods.Search_by_code(ptr->code)->data.num+=num;
        sellers_goods.Search_by_code(ptr->code)->data.num-=num;
        refresh(ptr->code);
    }
    void buy() {
        char condition;
        string str,clr="\n";
        Menu_Init();
        while (getline(cin, str)) {
            if (str.length() == 1) {
                condition = str[0];
                switch (condition) {
                    case '1':    //1. 查询商品
                        cout << "您要查找的商品名字是：" << endl;
                        cin >> str;
                        search_goods(str);
                        break;
                    case '2':    //2. 购买商品
                        cout << "您要购买的商品名字是：" << endl;
                        cin >> str;
                        cout << "您要购买的商品数量是：" << endl;
                        int num;
                        cin >> num;
                        buy_goods(sellers_goods.Search_by_name(str),num);    /////////////////////////////////////////////
                        break;
                    case 'm':    //m 初始化菜单
                        Menu_Init();
                        continue;
                    case 'q':    //q 退出系统
                        return;
                    default:
                        cout << "输入错误，请重新选择" << endl;
                        _sleep(400);
                        Menu_Init();
                        continue;
                }
                cout << "**********************" << endl;
            }
        }
    }
};
List<buyer> buyers;
struct seller{  //卖家编号、姓名、联系方式、售卖的商品编号(一个或者多个，多个以逗号分割)
    //发布商品、修改商品、删除商品
    string phone_num;
    List<goods> seller_goods;
    void Menu_Init(){
        cout << "————————————————————————————————" << endl
             << "|（1） 发布商品                   |" << endl
             << "|（2） 修改商品                   |" << endl
             << "|（3） 删除商品                   |" << endl
             << "|（m） 显示菜单                   |" << endl
             << "|（q） 退出                      |" << endl
             << "————————————————————————————————" << endl;
    }
    void sell() {
        char condition;
        string str,name;
        Menu_Init();
        while (getline(cin, str)) {
            if (str.length() == 1) {
                condition = str[0];
                switch (condition) {
                    case '1':    //1. 发布商品
                        cout << "您要发布的商品编号是：" << endl;
                        cin >> str;
                        if(str.length()==6) {
                            if (!sellers_goods.Search_by_code(str)) {
                                cout << "您要发布的商品名字是：" << endl;
                                cin >> name;
                                sellers_goods.Add_Node(str);
                                sellers_goods.Search_by_code(str)->data.seller_code = seller_code;
                                sellers_goods.Search_by_code(str)->name = name;
                                seller_goods.Add_Node(str);
                                seller_goods.Search_by_code(str)->data.seller_code = seller_code;
                                seller_goods.Search_by_code(str)->name = name;
                                sellers_goods.Search_by_code(str)->data.goods_init();
                                seller_goods.Search_by_code(str)->data.des = sellers_goods.Search_by_code(
                                        str)->data.des;
                                seller_goods.Search_by_code(str)->data.price = sellers_goods.Search_by_code(
                                        str)->data.price;
                                seller_goods.Search_by_code(str)->data.num = sellers_goods.Search_by_code(
                                        str)->data.num;
                            } else {
                                cout << "商品已存在" << endl;
                            }
                        }
                        else{
                            cout << "输入商品编号错误" << endl;
                        }
                        break;
                    case '2':    //2. 修改商品
                        cout << "您要修改的商品编号是：" << endl;
                        cin >> str;
                        if(str.length()==6&&sellers_goods.Search_by_code(str)) {
                            if (sellers_goods.Search_by_code(str)->data.seller_code == seller_code) {
                                seller_goods.Modify_Node(seller_goods.Search_by_code(str));
                                sellers_goods.Search_by_code(str)->name = seller_goods.Search_by_code(str)->name;
                                sellers_goods.Search_by_code(str)->data.des = seller_goods.Search_by_code(str)->data.des;
                                sellers_goods.Search_by_code(str)->data.price = seller_goods.Search_by_code(str)->data.price;
                                sellers_goods.Search_by_code(str)->data.num = seller_goods.Search_by_code(str)->data.num;
                            } else {
                                cout << "您没有该商品的修改权" << endl;
                            }
                        }
                        else{
                            cout<<"无结果";
                        }
                        break;
                    case '3':    //3. 删除商品
                        cout << "您要删除的商品编号是：" << endl;
                        cin >> str;
                        if((str.length()==6)&&sellers_goods.Search_by_code(str)){
                            if(sellers_goods.Search_by_code(str)->data.seller_code==seller_code){
                                sellers_goods.Delete_Node(sellers_goods.Search_by_code(str));
                                sellers.Search_by_code(seller_code)->data.seller_goods.Delete_Node(sellers.Search_by_code(seller_code)->data.seller_goods.Search_by_code(str));
                            } else{
                                cout<<"您没有该商品的修改权"<<endl;
                                continue;
                            }
                        }
                        else{
                            cout<<"无结果";
                        }
                        break;
                    case 'm':    //m 初始化菜单
                        Menu_Init();
                        break;
                    case 'q':    //q 退出系统
                        return;
                    default:
                        cout << "输入错误，请重新选择" << endl;
                        _sleep(400);
                        Menu_Init();
                        break;
                }
                cout << "**********************" << endl;
            } else {
                continue;
            }
        }
    }
};
void refresh(string &code){
    sellers.Search_by_code(sellers_goods.Search_by_code(code)->data.seller_code)->data.seller_goods.Search_by_code(code)->data.num=sellers_goods.Search_by_code(code)->data.num;
}
struct administrator {
    //删除买家用户、卖家用户,可将买家信息、卖家信息、商品信息分别保存到txt文件中
    void Menu_Init(){
        cout << "————————————————————————————————" << endl
             << "|（1） 显示买家信息                |" << endl
             << "|（2） 显示卖家家信息              |" << endl
             << "|（3） 显示剩余商品信息            |" << endl
             << "|（4） 显示所有信息                |" << endl
             << "|（5） 删除买家用户                |" << endl
             << "|（6） 删除卖家用户                |" << endl
             << "|（s） 保存所有信息到文件           |" << endl
             << "|（m） 显示菜单                   |" << endl
             << "|（q） 退出                      |" << endl
             << "————————————————————————————————" << endl;
    }
    void SHOW_ALL(){
        sellers_goods.Display_List();
        sellers.Display_List();
        buyers.Display_List();
    }
    void SAVE_ALL(){
        ofstream ofs_buyer,ofs_seller,ofs_goods;
        ofs_goods.open("goods.txt",ios::out);
        ofs_buyer.open("buyer.txt",ios::out);
        ofs_seller.open("seller.txt",ios::out);
//保存商品
        List<goods>::Node *goods_h=sellers_goods.head;
        while(goods_h){
            ofs_goods<<goods_h->code<<' '<<goods_h->name<<' '<<goods_h->data.des<<' '<<goods_h->data.price<<' '<<goods_h->data.num<<' '<<goods_h->data.seller_code<<endl;
            goods_h=goods_h->next;
        }
//保存买家
        List<buyer>::Node *buyer_h=buyers.head;
        while(buyer_h){
            ofs_buyer<<buyer_h->code<<' '<<buyer_h->name;
            if(buyer_h->data.buyer_goods.head){
                List<goods>::Node *buyer_goods_h=buyer_h->data.buyer_goods.head;
                while(buyer_goods_h) {
                    ofs_buyer <<" ,";
                    ofs_buyer << ' ' << buyer_goods_h->code << ' ' << buyer_goods_h->name << ' ' << buyer_goods_h->data.des<< ' '
                              << buyer_goods_h->data.price << ' ' << buyer_goods_h->data.num << ' '<< buyer_goods_h->data.seller_code;
                    buyer_goods_h = buyer_goods_h->next;
                }
            }
            ofs_buyer<<endl;
            buyer_h=buyer_h->next;
        }
//保存卖家
        List<seller>::Node *seller_h=sellers.head;
        while(seller_h){
            ofs_seller << seller_h->code << ' ' << seller_h->name << ' ' << seller_h->data.phone_num;
            if(seller_h->data.seller_goods.head){
                List<goods>::Node *seller_goods_h = seller_h->data.seller_goods.head;
                while (seller_goods_h) {
                    ofs_seller <<" ,";
                    ofs_seller << ' '<< seller_goods_h->code << ' ' << seller_goods_h->name << ' ' << seller_goods_h->data.des
                               << ' '<< seller_goods_h->data.price << ' ' << seller_goods_h->data.num << ' '<< seller_goods_h->data.seller_code;
                    seller_goods_h = seller_goods_h->next;
                }
            }
            ofs_seller<<endl;
            seller_h = seller_h->next;

        }
        ofs_goods.close();
        ofs_buyer.close();
        ofs_seller.close();
    }
    void LOAD(){
        ifstream ifs_buyer,ifs_seller,ifs_goods;
        string str;
        ifs_goods.open("goods.txt", ios::in);
        ifs_buyer.open("buyer.txt", ios::in);
        ifs_seller.open("seller.txt", ios::in);
//读取商品
        string code;
        List<goods>::Node *p_goods=sellers_goods.head;
        while(getline(ifs_goods,str)) {
            istringstream is(str);
            is>>code;
            sellers_goods.Add_Node(code);
            p_goods=sellers_goods.Search_by_code(code);
            is >> p_goods->name >> p_goods->data.des >> p_goods->data.price >> p_goods->data.num >> p_goods->data.seller_code;
        }
//读取买家
        List<buyer>::Node *p_buyer=buyers.head;
        while(getline(ifs_buyer,str)) {
            istringstream is(str);
            is>>code;
            buyers.Add_Node(code);
            p_buyer=buyers.Search_by_code(code);
            is>>p_buyer->name;

            List<goods>::Node *p_buyer_goods=p_buyer->data.buyer_goods.head;
            while(is>>code)
            {
                is>>code;
                p_buyer->data.buyer_goods.Add_Node(code);
                p_buyer_goods=p_buyer->data.buyer_goods.Search_by_code(code);
                is>>p_buyer_goods->name>>p_buyer_goods->data.des>>p_buyer_goods->data.price>>p_buyer_goods->data.num>>p_buyer_goods->data.seller_code;
            }
        }
//读取卖家
        List<seller>::Node *p_seller=sellers.head;
        while(getline(ifs_seller,str)) {
            istringstream is(str);
            is>>code;
            sellers.Add_Node(code);
            p_seller=sellers.Search_by_code(code);
            is >> p_seller->name >> p_seller->data.phone_num;

            List<goods>::Node *p_seller_goods=p_seller->data.seller_goods.head;
            while(is>>code)
            {
                is>>code;
                p_seller->data.seller_goods.Add_Node(code);
                p_seller_goods=p_seller->data.seller_goods.Search_by_code(code);
                is>>p_seller_goods->name>>p_seller_goods->data.des>>p_seller_goods->data.price>>p_seller_goods->data.num>>p_seller_goods->data.seller_code;
            }
        }
        ifs_goods.close();
        ifs_buyer.close();
        ifs_seller.close();
    }
    void admin(){
        string str;
        administrator::Menu_Init();
        while (getline(cin, str)) {
            if (str.length() == 1) {
                switch (str[0]) {
                    case '1':
                        buyers.Display_List();
                        break;
                    case '2':
                        sellers.Display_List();
                        break;
                    case '3':
                        sellers_goods.Display_List();
                        break;
                    case '4':
                        SHOW_ALL();
                        break;
                    case '5':
                        cout<<"您要删除的用户编号为：";
                        cin>>str;
                        if(buyers.Search_by_code(str)) {
                            buyers.Delete_Node(buyers.Search_by_code(str));
                            cout << "已删除该买家" << endl;
                        }
                        else{
                            cout<<"查无此人"<<endl;
                        }
                        break;
                    case '6':
                        cout<<"您要删除的用户编号为：";
                        cin>>str;
                        if(sellers.Search_by_code(str)){
                            sellers.Delete_Node(sellers.Search_by_code(str));
                            cout<<"已删除该卖家"<<endl;
                        }
                        else{
                            cout<<"查无此人"<<endl;
                        }
                        break;
                    case 's':
                        SAVE_ALL();
                        break;
                    case 'm':
                        administrator::Menu_Init();
                        break;
                    case 'q':    //q 退出系统
                        return;
                    default:
                        break;
                }
                cout << "**********************" << endl
                     << "**请输入下一步操作的指令**" << endl
                     << "**********************" << endl;
            }
        }
    }
}admin;

void Menu_Init() {
    cout << "——————————————————————————————————————————————————————————" << endl
         << "|（1） 买家     |查询商品，购买商品                           |" << endl
         << "|（2） 卖家     |发布商品，修改商品，删除商品                   |" << endl
         << "|（3） 管理员   |删除买家信息、卖家信息                        |" << endl
         << "|             |将买家信息、卖家信息、商品信息分别保存到txt文件中  |" << endl
         << "|（m） 显示菜单  |                                         |" << endl
         << "|（q） 退出     |                                          |" << endl
         << "——————————————————————————————————————————————————————————" << endl;
}
void Log_Menu_Init() {
    cout<< "—————————————————————" << endl
        << "|（1） 注册           |" << endl
        << "|（2） 登陆           |" << endl
        << "|（q） 退出           |" << endl
        << "—————————————————————" << endl;
}
void log(){
    string str;
    Log_Menu_Init();
    while (getline(cin, str)) {
        if (str.length() == 1) {
            switch (str[0]) {
                case '1':    //1. 注册
                    cout<<"您想要创建用户名为：(买家账号为七位数，卖家账号为八位数 按q可退出)";
                    while (getline(cin, str)) {
                        if (str.length() == 7&&(buyers.Search_by_code(str)== nullptr)) {
                            buyers.Add_Node(str);
                            cout<<"您想要的昵称为：(不可包含空格)";
                            cin>>buyers.Search_by_code(str)->name;
                            cout<<"成功创建新用户"<<endl;
                        }
                        else if (str.length() == 8&&(sellers.Search_by_code(str)== nullptr)) {
                            sellers.Add_Node(str);
                            cout<<"您想要的昵称为：(不可包含空格)";
                            cin>>sellers.Search_by_code(str)->name;
                            cout<<"您的电话号码是：(不可包含空格)";
                            cin>>sellers.Search_by_code(str)->data.phone_num;
                            cout<<"成功创建新用户"<<endl;
                        }
                        else if(str.length() == 1&&str[0]=='q') {
                            break;
                        }
                        else{
                            cout << "输入错误，请重新输入"<<endl
                                 <<"您想要创建用户名为：(按q可退出)";
                            continue;
                        }
                        str='\n';
                        getline(cin,str);
                    }
                    break;
                case '2':    //2. 登录
                    cout<<"您的用户名为：(按q可退出)";
                    while (getline(cin, str)) {
                        if (str.length() == 7&&buyers.Search_by_code(str)) {
                            buyers.Search_by_code(str)->data.buy();
                        }
                        if (str.length() == 8&&sellers.Search_by_code(str)) {
                            seller_code=str;
                            sellers.Search_by_code(str)->data.sell();
                        }
                        else if(str=="administrator"){
                            admin.admin();
                        }
                        else if(str.length() == 1&&str[0]=='q') {
                            break;
                        }
                        else{
                            cout << "输入错误，请重新输入"<<endl
                                 <<"您的用户名为：(按q可退出)" ;
                            continue;
                        }
                    }
                    break;
                case 'm':    //m 显示菜单
                    Log_Menu_Init();
                    break;
                case 'q':    //q 退出系统
                    return;
                default:
                    cout << "输入错误，请重新选择" << endl;
                    _sleep(400);
                    Log_Menu_Init();
                    continue;
            }
        }
    }
}
void operate() {
    string str;
    while (getline(cin, str)) {
        if (str.length() == 1) {
            switch (str[0]) {
                case '1':    //1. 买家
                    log();
                    break;
                case '2':    //2. 卖家
                    log();
                    break;
                case '3':    //3. 管理员
                    log();
                    break;
                case 'm':    //m 初始化菜单
                    Menu_Init();
                    break;
                case 'c':    //c 清屏
                    system("cls");
                    Menu_Init();
                case 'q':    //q 退出系统
                    return;
                default:
                    cout << "输入错误，请重新选择" << endl;
                    _sleep(400);
                    Menu_Init();
                    break;
            }
        }
        else{
            cout << "输入错误，请重新选择" << endl;
            _sleep(400);
            Menu_Init();
            continue;
        }
        cout << "**********************" << endl
             << "**请输入下一步操作的指令**" << endl
             << "**********************" << endl;
    }
}

int main() {
    admin.LOAD();
    Menu_Init();
    operate();
    char c;
    while (1){
        cout<<"是否保存（y/n）"<<endl;
        cin>>c;
        switch (c) {
            case 'y':
                admin.SAVE_ALL();
            case 'n':
                return 0;
            default:
                break;
        }
    }
}
