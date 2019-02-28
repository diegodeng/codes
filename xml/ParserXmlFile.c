#include <stdio.h>
#include <libxml/parser.h>

int main(int argc, char* argv[])
{
	int ret = -1;
    xmlDocPtr doc;           //定义解析文档指针
    xmlNodePtr curNode;      //定义结点指针(你需要它为了在各个结点间移动)
    xmlChar *szKey;          //临时字符串变量
    char *szDocName;
    
    if (argc <= 1){
       printf("Usage: %s docname \r\n", argv[0]);
       ret = 0;
       goto done;
    }

    szDocName = argv[1];
    
    doc = xmlReadFile(szDocName,"GB2312",XML_PARSE_RECOVER); //解析文件

    //检查解析文档是否成功，如果不成功，libxml将指一个注册的错误并停止。
    //一个常见错误是不适当的编码。XML标准文档除了用UTF-8或UTF-16外还可用其它编码保存。
    //如果文档是这样，libxml将自动地为你转换到UTF-8。更多关于XML编码信息包含在XML标准中.
    if (NULL == doc){ 
       printf("Document not parsed successfully\r\n");   
       goto done;
    }

    curNode = xmlDocGetRootElement(doc); //确定文档根元素
    /*检查确认当前文档中包含内容*/
    if (NULL == curNode){
       printf("empty document\r\n");
       xmlFreeDoc(doc);
       goto done;
    }

    /*在这个例子中，我们需要确认文档是正确的类型。“root”是在这个示例中使用文档的根类型。*/
    if (xmlStrcmp(curNode->name, BAD_CAST "resources")){
       printf("document of the wrong type, root node != reources\r\n");
       xmlFreeDoc(doc);
       goto done;
    }
    
    curNode = curNode->xmlChildrenNode;
    xmlNodePtr propNodePtr = curNode;
    
    while(curNode != NULL){
       //取出节点中的内容
       if ((!xmlStrcmp(curNode->name, (const xmlChar *)"newNode1"))){
           szKey = xmlNodeGetContent(curNode);
           printf("newNode1: %s \r\n", szKey);
           xmlFree(szKey);
       }
       //查找带有属性attribute的节点
       if (xmlHasProp(curNode,BAD_CAST "attribute")){
           propNodePtr = curNode;
       }
       curNode = curNode->next;
    }

    //查找属性
    xmlAttrPtr attrPtr = propNodePtr->properties;
    
    while (attrPtr != NULL){
		
       if (!xmlStrcmp(attrPtr->name, BAD_CAST "attribute")){
           xmlChar* szAttr = xmlGetProp(propNodePtr,BAD_CAST "attribute");
           //cout<<"get attribute = "<<szAttr<<endl;
           printf("get attribute = %s \r\n",szAttr);
           xmlFree(szAttr);
       }
       attrPtr = attrPtr->next;
    }
    xmlFreeDoc(doc);

done:
    return ret;
}
    
