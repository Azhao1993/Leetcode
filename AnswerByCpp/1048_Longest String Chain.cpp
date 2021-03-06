#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*
1048. 最长字符串链

给出一个单词列表，其中每个单词都由小写英文字母组成。
如果我们可以在 word1 的任何地方添加一个字母使其变成 word2，
那么我们认为 word1 是 word2 的前身。例如，"abc" 是 "abac" 的前身。
词链是单词 [word_1, word_2, ..., word_k] 组成的序列，k >= 1，
其中 word_1 是 word_2 的前身，word_2 是 word_3 的前身，依此类推。
从给定单词列表 words 中选择单词组成词链，返回词链的最长可能长度。

示例： 输入：["a","b","ba","bca","bda","bdca"]    输出：4
解释：最长单词链之一为 "a","ba","bda","bdca"。

提示：
1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] 仅由小写英文字母组成。
*/

class Solution {
private:
    int iMax = 0, iMin = 17;
public:
    int longestStrChain(vector<string>& words) {
        if(words.size() == 0) return 0;
        unordered_map<int, vector<string>> hash;
        
        // 数据预处理，先存放到 hash 中，方便查找
        for(auto it : words){
            hash[it.length()].push_back(it);
            iMax = max(iMax, (int)it.length());
            iMin = min(iMin, (int)it.length());
        }
        vector<string> arr;
        int res = 0;
        for(int i=iMax; i>=iMin; i--){
            dfs(hash, res, arr, i);
        }
        
        return res;
        /*
        // 动态规划
        int n = words.size();
        vector<vector<int>> g(n, vector<int>(n, 0));
        sort(words.begin(), words.end(), [](string& w1, string& w2){ return w1.length()<w2.length(); } );
        for(auto it:words)cout<<it<<" ";

        vector<int> dp(words.size(), 0);
        int iMax = 0;

        for(int i=1; i<words.size(); i++)
            for(int j=0; j<i; j++)
                if(words[j].size()+1 == words[i].size() && isPre(words[i], words[j])){
                    dp[i] = dp[j]+1;
                    iMax = max(iMax, dp[i]);
                }

        return iMax+1;
        */
        /*
        // 构造图，超时
        int n = words.size();
        vector<vector<int>> g(n, vector<int>(n, 0));
        sort(words.begin(), words.end(), [](string& w1, string& w2){ return w1.length()<w2.length();});

        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j)
                if(canChange(words[i], words[j])) g[i][j] = 1;

        vector<int> lcnt(n, 1);
        for(int i=0;i<n;++i)
            for(int j=0;j<i;++j)
                if(g[j][i]) lcnt[i] = max(lcnt[j]+1, lcnt[i]);
        return *max_element(lcnt.begin(), lcnt.end());
        */
    }
    void dfs(unordered_map<int, vector<string>> &hash, int &res, vector<string>& arr, int cur){
        if(cur == iMin-1){
            res = max(res, (int)arr.size());
            return ;
        }
        for(int i=0; i<hash[cur].size(); i++){
            if( arr.empty() || isPre(arr.back(), hash[cur][i]) ){

                arr.push_back(hash[cur][i]);
                res = max(res, (int)arr.size());
                dfs(hash, res, arr, cur-1);
                arr.pop_back();
            }
        }
    }
    bool isPre(string a, string b){
        // 通过双指针判断, 默认 a 比 b 多一个字母
        int len1 = a.length(), len2 = b.length();
        int i = 0, j = 0;
        while(i < len1){
            if(a[i] == b[j]) ++i,++j;
            else if( ++i - j > 1) return false;
        }
        return true;
    }
};

int main(){
    // vector<string> arr({"a","b","ba","bca","bda","bdca"});
    vector<string> arr({"mruintxkxdkwdpfi","bijfilrctofmbfez","qjalbgicmjartptq","fabqpxcqiubdtswb","qbiyncckblbdhspd","eeqfobwqubwwahca","ihadksppzntbwcuc","xfuiwoltlvdcgrxy","osurxkkxniiujxrm","jbrkklnwvchmibgq","hhdoeypdedgmnlra","wapnrmkrknoaihys","tgqaqqbzrmapbusr","dmdgzsellykttqas","xohrxjivddanlgfw","ufhaawgedjwxiugn","xekdhtaanaanemyo","oiphmcyoxmqdgtnz","olrkclxhuwukosnj","yquxjjvuhdqefflr","gmgeacdxnuzacfkz","ivaxbwgzrtelbfuy","efbgscqhonqzpqaz","jatcdaftuvvupnsl","olljntvjamxgejmb","hkmxdqgyvfurupnb","snksaifnvzgiwjhb","keqmebvybckenaen","risgzbfrsdftbvrx","falcnebeauknzgxn","dbcwoigdqfnximlm","duqxtaecqjuipvsb","gmamjcysovwhsvhx","lllyssfmuxzadxeq","ydiqardapykexogo","foazrdrpaxpkcjkk","aqbebatfqrpdjgfs","qmmqnefzhiajmfax","gxqxiabuotnukozs","yqatxophicvzuvwu","flfbumalkwsvadgh","czqtqxggntqjhqjp","yrqjfteswbuxrrdg","apdyumogmjcmcwez","sbiztxrdslzicwjb","afewyoialybaspde","gjgynpjyfefszbtr","hygyjhowvrrrampn","mlblznnbedgmtmki","uvkggegvoqpxpesi","baqqaufnljrlbnph","jnhxmbcqmsmihrti","heobzgqczqsmttgv","zzytphiczwixasud","euczteojpswwmwzk","pzjidwcueidcxcdf","ykruuujwwfvqnbrr","yoclkanmvcvitbwi","tbiccwsllrcqcqbg","gyndhffwgdxmufeo","pannsofbnsivbmlf","fzakhoztbujunpjs","wwfiekvnhsirqqbq","lpxlphlrvcysgvpd","nminrfessckjkues","jarighnupdswdfzd","xcnzsxmesclibupj","clmvkqvhcttbykqv","jfcphrovfmgqbnco","evqorpgxblklyzpv","jacqkrfqpqhqdljn","ocuqzzbuzbxmwujc","gfzhfetfleymvpxc","vwclqcbtfpmopcia","oofmhgzgyycargbw","rleucaqkatiojfwi","wrfdiouxvbyqvnca","qxufakmwrtzzlsqa","cgctjdnavncfcqpz","mczccfvcgykhrzst","vmatibsanmotfowk","wyxotksjglhqxeag","rvauwpsrsnrznbpy","xgqqnywxqyiulsmk","opdjrqcvqzmrlrrf","axpzrpzsafljkcqg","txtmhbcirmtgfixi","wdmpzaffoujwoifm","tqnnfkqvaedwnfxs","oxfqyklmqiyvfoge","jylsqqpswhuwfiev","bhaafstnzhfddiit","meczkmjswzjcwtdw","mubfbcsgmiztxfth","gljhdpkfchzixipz","smezveohfolqrlzm","hdupyzgvjeyybiqv","ctyrizshewwkkisf","mmhpkusicmdqllhl","recdimiptqupmbfk","utdudpmcpcktfcuv","qtcehonrauamqgbm","irngjliuftfgwdvi","ldztinzpcueibave","gbrkxgkjpwhtdspw","wivmdwwfojwvhbfp","fsqpltcpqqvttqwc","rabaafygwroceavg","eimrdabihrlchcxi","tkscmyfsodmyofph","wodezwqeyygflzpr","pyullwrfadpbyqim","ngrsolixhgqdvgyf","cnholxhbpetmdgvj","xekyrzogcmyqkcgo","ojwpsdohtnhxiacw","oisuqexhwgrrpwml","qmuuyhdjmarwfuhl","xyokezgwicihqvxc","zsyatsedhwwfvhdu","inyjwagxfhrzevkz","ehlrvyhdxqjjtnzk","silgjlnrbbpifiwe","dpzfaupdtbmablxn","nvbhcjdsheospxaf","nxvkvecmckiuixxs","onmbiplcwmzqzwyf","wwucjigywmsvvctd","aseirafixhyubvdd","cbjcyeqhqcbhpqop","bcndizlmpbeqiftm","iffiuuxswaettvne","okwlnepzltbpxtdr","mtzncfobkidmqeye","vqlkoyddaqvuuxvn","stouzfdybjqpghdi","dgqrspdmszseqtvf","skhdehrvfckvtfhh","qnvkhptisjucxibz","yjgzpaongozflwlu","klkshyckyoygflwi","patdhvhfacvaxgok","tytuovjsamervbty","vobaiiluuxqqwgub","jocdzonmdmbihklh","xtleqvoyhpztmxeg","lukhueeydmqlgwhr","yaprwkimjwxruhyr","cqaonykopbltkqzo","fnzvyhwabxgiikor","zthmobpbvzqfchyc","bkgmwqxomjmtlvmk","xdmaedpjmbyouddp","kvcoezecfoorubta","vxglhhukrwkogiqu","vdvjgghgmxfskxxb","hyygldpkhnrksfhz","dwuripjnzvufzzam","oovnefkkkowovnqc","ihwoxxrgcocvrvzf","bziomioajypdwtug","blgkinajcsfsqpce","cejxyajllbnuvxlk","zexmjrjpsnrjcbtw","avlvgyeelzxpvpzh","shbphtrpowjnmsjd","bksfyfcnmfhleldx","hwmepsdscdpvbbpv","euycxcpmcsezdkol","glydfzeeqbvyuycf","xwqxhqlzfkhyriks","xgfsncbvptnpgisj","ejsjntvhqjblxjhk","ucpbkozifzgoebxu","taenpkcsqolwxjyl","xxdzbmemhinlpfhb","salryjmlxzxhqccu","rfgyukwfqaibocsh","tvugunpuklqdzqxs","ykbxzttvowpwtnpi","muallgurfchryxmi","adxfntmiikcdatrk","ghcrxcwadoapvavh","ywavyacmlsnlloje","dhvwihyrgachcbts","dkkzflkqkqdjjlkz","wbgthigpcnokvrql","epeniaqywphdhtwe","ufavxzadutjalevq","astwubhpykjmqqmx","aqckajnzpgycqzao","acenjflenbapdfyy","eujwzmsrodmdpxua","rpmgzhpguwqoizcf","jejpooiknojrlsml","oejvfxkshkbhhosi","avrciyfumgmrnnet","okaazaillzfxnrhv","iodnneooptjujbns","udtcymnndgyznral","wvzoxdjmmrmdfaub","wlpehwqvpgjkftjc","yyujowmwuhclwlmk","gzipvnhwdqdokhod","nszxsczkzmzyfdng","njxbgvslxfvoffyt","ciifvkkbqjkbhhxx","kelhwxbswynuoovs","zldrqukkmuvaidxa","jskrphkoffljtwix","povzxukrxzcxcmio","pcijddltvsmtlouy","ayzoinzahkeaoejj","pjtfvkpusqeorwgs","zfjmhadjolraldxa","vwzmwtnexgcvbfoq","qxcnuqhguhoujwli","awxvpcswjiwegiyv","eruglldmevgadjlb","grrlhavmjcjjvllm","xsckequtfxzvipcu","rqncxgzixnkgzuhi","zhmjbnknxozyqggl","wreewoqcywbmbgko","hmxgbarkymvzlnyb","nklrpwasioihjhwm","ngptzoaimpffvrnp","osnehfntrxzieosg","czmwoezwfdpiquuh","ykqehucwknwsprzd","pgiquhyaxifqtrac","mhwqtkelefllcznq","giggsezrwogdgbsm","ppktuttzkjhttfyk","krtuwupqjkkjgiaf","nvohwhyeguzxismj","tozwpvnflkztrbov","dbokqtjxxbbjsdhh","ztdwzprcjcbffdst","krynwlhkzguctxyx","uajtldhphlxqufcp","dbcgvxsbnlozlmhw","olmrysiqfhpszpzz","wezknyigipknwsgv","snnofaxdkzynmmra","uacoalhuteifzdqy","nxyxhgdstvhtawhf","hrsqhzbiggluqxkd","aoglduapumrzbuir","jviqkqenrkssqaxz","tpragnvauushzjhr","zorulkcggkafebka","zmyxwzwcljglbbst","iphfkhjpvlwvgzfw","kqoyvenrltsdekyg","xruesuagvadkhsjn","ymwnuzgehegphhid","mnxvkocgaxfzoqzl","vpeyuuuwqftdfgnf","qbyxuuwnfdhkdsup","uaoeofrbnwawffgk","wqxrzjpgklufccdh","tsekyqzffcowcisl","qsjfjsjaqykcnckk","vunytqtuykurjiac","axrqztnlzxpqbnaj","iaqnzbrmknaffmwa","dfrpyhjfxrevyucf","sxcopaxqqohhpqsi","doaomwlzfbrpllwu","iqsqjsonpnrnutkq","pnbllvnuubruyogi","kxpjdtrkurbxdins","xjqjascggklshcfo","bwzncsfgeqkcybwq","ixbfexflrzhvlxus","gmwcwokvlkpvaaja","wbwedexnchulskyl","zkghqgachnghnsdw","hlrdjuwdsrqavdto","iulpkqieoiuulfep","vdhmjrkmrgojozdo","umzbnrwlpmurdzug","jospmhpjfughjkss","bamfcvcfypuwjjgg","ealbchtvwpsgzfme","porynrgqbqioqiox","dbsnnrarpplatgfb","xteperreenjsfocm","egwnqrbxskmurwuj","ohcigmeduxpexzbs","qxzfxnausevpgeyr","hyxkezeqsnzphqls","fhpktgwzqpslgndh","oiyifrvdnxdjelux","kuvzegsiatvpgrxz","icnmxfgawrdfoioc","lsomvkjxgcgjuqvp","keyzeqyvivrnjcjs","vzgyiuiekkadezmi","xvebiekowzphagro","fcxrtxuffzjwygpm","qkkpfcnhkkxniqpu","qagpqqdlbgfguorn","jrqzdtjvjjlocbyv","jyotnvljcjcpwlkr","aphxfcgxoqfhvsrs","zwhyvznqvofbropl","gbxkslprjvwibdkl","eksnrddyxdrartuc","naurhtorhcgaccsp","vnqgcsnjjlnpnytr","dxgbnhkpvuklukdo","bmifpmsjwdltgjxi","vrepcsfberespqhe","sgzuhufwxbcprdir","jkjqlbwielzrofsd","ocqkuxeqsvfigavz","hhzelfsutxpcbriz","xmryipwkxyaaksca","vlbtxgbsziuetdpt","hkhkcmvxibtdzzzi","efmcwozrncsytbxv","whhsdzhmdksxevrd","escmhceotzsrkjdt","vsgtydoodyxqidpw","yedikxqcwonfmdem","qwozmkkpxdklzipy","uelvkcafoivbcezd","xcnfvvgdchmhsiob","mlllocfpapwqrcbj","qhjitdfjphakpdwd","msijlhajdjjqewck","qbzkmiiibfhicxbs","btzozehrcvoglofj","qqtsrnuvacgyvpxl","hwjycjocxykhhbzu","buucsanmahczfipg","ibhwigjeriagncye","cuhkeczyyyootgjn","ijpqdanxejrxqraj","gldqgczzyengkkpk","ifxhmytuakcvlqnd","yfixmhrtttqoaneq","mgpionyeuzpcojos","ldpmfziankygudyd","psppgaosgdaywpij","nsbxvqikoernqish","crobddmjqdxcvtlb","jjkqoljvhkndagxp","aqgnqhrhocfgohgx","ebsfatfnrppiiibz","grctlbxizczywlyf","eiqzxkanhvccrhby","ytmdlysmghpbvkxp","xiktxiqwkfvcfiil","yegjgzcmcppcxjea","xfmlyqhvzyobujol","unqckrqmxwulkono","gcibxmuohmhewltm","blyyhjgxzacrqjnm","eexztefguwsfmqtv","ckobcqxiteqsmvbk","myeyhcszdadqvfiq","uuvjlgiiarrxpxmm","wnanamrmpobtwzxc","azvfxhsrzqfcjhbn","sdjjuezpulwhuhyt","ykzykhyxqdpohneu","tpuheqegasjgilkg","veivbclvkfsrwrgh","bdbgxvokqouplpcy","nldecbvwbzpzcuyi","tybaeippnvxrdglo","tnrkijbyjiaiquyl","qeyynrionwyrfctm","fkuryinibritptaa","uibaswjoljdbyavi","sliintoeacitiusn","pclbbgbxecjjnnci","wrpladdbpjaxegio","tiknwvvoxmznmihi","oglvtjbzktnambkl","ccbfeqmcmobzfquu","vqyhbfqmwktrabhl","goxwawdjhvryuevt","vuyusxcmrgleusmm","jhxskuflrgkqjxie","aoebxzsejrkdungh","qzlwkhayldtgjhta","gxzrvgauitkyqtpk","thqfbfewcpxfygpq","aphcgqkxlmbtwuaz","wjkvositriinncvj","hzdqvprmwspjohjv","iiutqqorzyncxvwc","tmzgsbeitmwkazti","bgmcdsxhqxudmogz","htlcfnmzufffzave","wyjxdosviffmnkty","enffsjxdgedolkip","jmqwszfbsaiiurym","pddtdgskllhdilft","vpfdmiwvqhzoxngh","qrgugpeshkhwtoih","nfmvcyyruhvbxoue","vqnbxpruvicyhlip","tcrozcgaauecfemu","bvmkkmezbimnjrya","uerwfaxhpiqcrvcy","uagndllffwfquekj","czqstoypaxxxbglf","wgzjwoccvwkgtnhj","cwqjgbtffjfnqcwd","entufhsfywjwbyql","zbgktzsqfhyqwamf","cogjdbfjhfejflmk","ornkrmuabqmkxugn","cnyicahjscxpbwfo","lmtsssytsjrltjzr","djfpmmzthvbidbvv","krolmjelcccwkbye","nzhmycerlpweojno","zbyzhmrbwggejidc","pnhpbidnmwrrpkko","cpnjqomjwdsrkebs","ifuedwjqjbpudccy","rwqjpqgpyozzrind","ccipgxvfhacztvqa","rguaiyblkpkjcdhk","aiybfjvzxhlqzgdw","vtgygkeuzsnqavgr","vetpeztahnmgrdoq","qsllcctkmzxmwtam","elreznpuuuiseniz","xjnalrbbxpzqamak","upmbibbpphabtrvt","vmufbqsxfvuxcxln","udwwfpeocioaybrs","orniprxhsjxsqxbq","kctnopfeglhtltvk","xlemfwjplosbdvbu","huzmxkcgvttsroec","qwrijbgpymeuplei","bdpgvvrhqpieiowp","yyzjmaoudobqqlqm","wppthqgwvnqcozlr","wvedxxfsbkrrmvfm","itbihbagxvxkjvlv","nctovfkgwcouyhzi","jwbezhubdgnhslvh","etfmnkddjtpsvkba","gjynrnuzoduatouw","qvuhgxjalwhjqbpb","ygbdkwwyjzawyjms","xpboswfkkssktlfj","ijhzkwdeuxkcnvap","etibuzwahzfwffaw","kqnjmhxqgyawlatb","rcqzoxpmojgmymdg","remhhmbwrfoqckbg","egpfcenyxvhmbize","jxdlkksgkjvjrfcw","mijjpvggpwjvgfdm","xzlqvlzafflpumar","gvwekgmldiawgoru","sspsbjdciuxgxmoi","qxraingfxafjaqds","cqbjakpijrzavwcd","obfnunhuupfafeht","zdimdppkbtnhfjmn","lrwcrcljksrbzewe","wgoswzmovlklplls","lalsujinqcjvpznh","gtswdvkywyswdjku","ssajoksaqtakukhq","tgcmiwecaevpxwmj","wfftpnjyigrnmuwh","jpcsboiqhlgsquzv","pvvcybtfrhjolbku","zfvzkjdrcolrcgjp","vynmjjfvrcyxglue","mjrfkxjhuowzwast","ubzcfkstxfdzwdmz","klhuanxiapbtbpik","veckdyzcamuusjhx","dugzbqezuathclrp","hzygzoqrinjomjwn","dwhrqgqjotinuxuu","rqqtvpxbmbvvwwab","dfylcarddcuwlqrq","ufxkudfjlhetmjkm","loijppylvkebkcjz","islxgwnhkcgfdfws","jivolhgerhraywod","ftlxyjsmktbpdimw","afldksubjajslcoe","ekjeelwbofqikgyg","sntevrhhyicsatgd","rwpqcsmwlcntlwpi","uihvskvghmhtapur","irxeccdtfauyrkyi","hjfyznugwaalafxo","emjyrqwlsrktpqfz","qqcwajbmzvjrxxup","xlsmcwmuwlsizpeb","fjevzpbqhjbjwjth","mqhfligcukjzohym","otgdhuscsdqfpfhq","bpscndkvbaxmhxrq","zagckkdltahzztop","tdvfxldgxdijlkew","kkooujbtpyzkreno","mnmzyevdbdhmxmzs","boofizexnzxqdibf","pqskykkvpgonqzdc","smkqwuuewebxsmyt","iokyrymvlreurrgo","phaglhgdsjonuega","ehxhldcregqzdfch","xllggguimqslvyaw","infgrqrridfgpmxt","wtscqpzbmkdvuxyn","psomagzzdcnejvgr","lmqmmjrqpvnvegov","ppwvofpblvurjnpt","ywxpwjoqdfjttekt","apxfsxovprzxnvxm","vlmbljkntghzdfyx","jugxriyrxwoqslrn","rltjvutighthbswn","lykgggxykskquejt","glgamwedyzzvqoua","giwfjuvxmlndcabf","xqggyebdkqfrexjs","gsqkruwrujptxozy","jnhwoojmgqxkabpn","emxbpkzmjfqgmhmj","uwmhsgpnlfbkrsxk","gqgruhmbnjzrbqsd","ioznybroipgecmhz","nejwrlzryhtnvouo","hjxrfsvjrhoxzooj","bnejwwrvtqouyuej","qexswmbeeltumlxy","echammdfkgemjwnr","bxvtynqtysoqgvye","udyzarnzwzklheru","hgldmdnnvadfckht","vnnwansetagwfrbt","nrzhalnwothjgikx","crbdkqarxxwuvwfw","znpeutlfmcbmxgfk","kiammmhcwjukawdn","neqytgtkmfxgvzri","huoutfxacddefaqm","ncbqpbbgeozeyfna","enoblviderjrumsh","llvuafxynryetyvb","agsgdytbrxzcoboq","kssmvbxbwdhocypf","ocbiozxsegjsmzco","nbzytpguystfkkkz","zzdjhnrqpnqoktja","hxwnvmumjxanozqr","ohkrsuomrmpsohfh","uwqkhqxmffbmkkhb","aymcyhmpagekafou","cmitwtungkwfkbco","wbrshrzispsnsdms","ffmkzvhdihrtaejr","ytslpetispazbruu","bwsewoimfbpbrnqt","zqiohpwpissrcfnk","jcwerukwiwhthjzj","vltrydbdvoshgdsr","sxxtbgkjzuklblhd","rzmqwlfoqgynoium","ivtyfvtgkjhsbdkp","aeovbpldmhrihtbr","mnmyeaqdwuuhlhzd","yzytjaetylnckjkb","bnrblqoctgmdbmev","safaxohrubtwvkka","svrrfidasopeqpjg","nlzzfihzizbxuxty","gukfmtevclbwckxr","uvkqpmpooexgnchy","gesiiozcuajcsrbi","efqykzvpxtuwzrkc","yrksbyjbwjifgdqh","nkaaoegqzazcrptq","mronksidrwbuqccd","wazskerwoemxkyxk","lueshyclbscvwmzm","mddozzxpvaaoyahz","eolyxvmfqrcklkbf","miwziupwmqjriyiv","hgmwmqphdtaxzvcl","xvhfizicdksdygwu","qsagovnqiobbpcgv","lqmjymmpaudpnque","jrnftrisienxvcul","qgyngutblmprxaex","wjwvmcpsfgysowey","wktvnkoveszajowp","pebkethdpzczryms","zocgxnxlslbwwqlo","kyndkkctvskixlkk","enwlfzfzbycfgzmz","nxxmhneoucffvtpb","cbipldhwpsmhdwzs","ctvjvshanwoxhchc","edfimhvncbkvfqyu","bufgxhevpjzzxqlq","oqjbwuafbvzjbumi","hrtrfslhyltokmih","ucmipvimzpcgsemz","pgmrlrommjibqmjr","aipeavuumiorldvj","ijndnbcwrnbvwrhq","ofhvwopozismohur","irvzhzvpprsmebkf","qxwmscclbihogkpf","hycmtbpeqjxxvirh","zbzvvawmanvthgqa","ainwypeilkapzfaw","bxhysgrxvsovucjg","tiwieqcaspmatnsb","bxvedxmpdcecmmur","ewpmxsvoaiwtlnwd","qpsaufheivjogbhf","bjleerpvaepwleqg","vtrttlofyhjeybgl","ounnshffydsgindo","utmgqsgxcdtkffsr","dpzqacdivlifadqb","mioaftivgcymfnnb","lvrajaenrwksfrgm","elcdjeowjpbukqwu","nkcsjoqgycmtmqgb","nnnvwvbxneuycmwj","fauzzvbbwldwjart","kvaqsszcswuevepv","acktpeenaaefkjyb","sulhzdzlrlndzuwr","rvvszysowdoazsnd","nnhmxxosnywdacxc","ymxmivmupyruuglf","vqvnndlwtgzxdcgk","yqypyaooavoubxqy","enmnzozozvbbossb","yyefpxzocsgtbwuf","nzanylfgauktuymz","mskwxvvflhsqjhgy","wuwnfemvzvnpviks","cfdogixhdpaxlxsh","tbrenytixgzxuwyo","vlvllvqgkzdaulfe","ivsnolkdztmothab","pzdhtcvsmqrcsdnt","qbyxykpspgnkltbj","phnymcjoxhezzfjy","raodeazbsurnulxc","ezimpfwsljeuczqr","cmdmrmbuvvifnejg","hrmkklvrmdqxwguo","rsfliocvtlhzxkgk","vtugiwucljnamblm","coluzqpdcbhttwoo","ydrzlweaxceubehe","cbnmcwuntoijmpfb","ycwabkunujgrebpz","kgalzxsovqiqkboy","vxraohxzwureaspf","vbsdkchbxwtjsomk","ixnurotgwfieiwhx","awnregzvujprqllk","bezbeevjckdzmmbg","iacdsvofkntqrlyr","nytmqqqrzeonsqbe","ydelmraophlnjfiv","zahuoogxdqwfxtjc","ruofuruokhnmhsxt","qhgxrrhqrfmcotob","kwfmpciwxgizdabq","wboozvhpukpngkyn","dyhiwuyrcdwniyki","rhmfqwzsrpktrqna","ohcyrjnvbzygtrtw","azsocmwolusbktnv","ukwhtkcpitckoogl","rruyrlisjufcowxd","todqbmgtglzqkike","shujmewxzgbtacau","mgclpfzstizusbgj","gfyxynyrwnrlfcnd","jjotzowbunzvipos","vclpvnstdbqpavcv","sudtffyppylzzzau","btkpehhzxgirjtvq","fpsotypjrcbjnwlo","pfpnofnufdropadp","uzkmkgdlyvwmdwlq","jhuhvtadjyxfrkzv","oabnbbmlueumwzmz","xmpadvtmnrtoevnz","mkgmkpzaapfazolc","egltcbnfgiyfjjjv","sqopppyfzefrwmsn","syxaonsislnxpnwa","ytdpzeyhjgesjiua","ogwoerbaenhljbjm","dyrqrszhfxlehktx","gbfdubiktuwwjogr","lpdrydqpcktaxvxd","pfwxjspybkksaqcn","awvkytqcrkdpjsdx","olaradqbqkovlnuj","phtjrirdvymutlhi","oseqagozmypzpveg","qynxpnorcxpzvxob","tyxxmcwiorjrmrfr","seoanniuqbzwsbth","ymrytfpswehkgmin","ophklncwpseuauvb","clnrerwamqfoiawq","ajnxmmucjwbpchmn","toppdpnmahkcymoz","iploiqqvgnsmzppv","jmqfnjwxznbnfkfj","rxgxjxiihaibagws","dwcaguzmzwbshaoi","oowbyvfmumvixttg","uxnpojssgbezkjhh","thpfnyogfevitxqb","dcsssbsrhaggxanz","alhlinsutyenpaoc","mgpxwwehwjbizulv","xtrzwqgmmfsnaoyf","opustpfdcxfxvysy","rstwithkxpcussoy","lfdsjeuufrwashhz","dqoftntvffvydcyv","ndogxowlfrrjuogm","vhzrzycziqfvpnsm","neamepqnqitepctk","ylsfubzmmwxrsbls","nrjavmsmrsiwbusb","vddbumppbeclvfrh","djmqmrimjogtwkty","zacvcygqzguodzcg","vneahcsoolrgkzmh","mzbxreirqcybalqf","qlwsvogwnjejpmmi","fwwewafuehcnuvwn","ivddyrnfxkwergli","ftdaonpkldpwpucf","xwexnjgadrutrvwh","hbcfhtkvbszklczu","iogrfbqwqvxanzel","hedilczflydxjyvo","xvfqlfqitjuevvef","ntjoahkxjetuopbz","dzazlcdkqdaqjkbs","tbgdedtrjuhlhffv","apmruvcchoklkxkb","yqjiviynazoisehi","xcrcyvhozgszjcig","bcixgxdjocrmaovl","rmjexwvdyuzgzzsc","yalfzddkvprviife","kpbavoqxifplqtgw","rebruzhtjzydnedj","yjqhadcqyowgwlnc","konrqcxvqxhwxwfs","itlolvtpmtqwpnbu","neokvokxeqmhyvij","ufhnjdpraoagszdn","kbvyofcqaejzdssx","xmshhdfbpwneacgr","jqbqdatswwtwotaa","isthhksbpyqyurql","lhjidlxglqorfdmh","behnwnwicxqlvhdt","vikyzimvsrlrzdhp","gmvimblojeslflei","raacjwiszerxeqbj","fskdjszumgrohjlk","ctkkdfadcfobfevq","xnzqlwstspukvfkk","rubjhjqdubozxmbu","yxhkyfjvwjwikfht","rxmvzctfgjugealt","aycrsdqinacccyfi","icfclxilznmcvnwn","ivtonnwaokwlawcz","dtrkbjeyjtknnsvh","urwfnorlbnwwtcrg","khpnvcxtlzvfunla","szjfxrcqzzyerngd","qxoaknypaxycmzxy","vgoxkwvwcuolwzmr","xmyxjzwjfzvgbvab","vnmiwkfrsjefshsy","zmbhzgojbfzinxbr","srbzmvbqdvtmagxv","hhxlmirazeehxnxd","yftjgflkxfxfekov","gaermgunjcljwjmd","jungglftuanipujd","zifxashaxebfqntp","xfrnekivukasauhp","gzrylfxautjzzhaz","djfklgadgyjtivnq","dirdjqdhoxtmktsu","glrnsfmaqlrjnafp","qdcpdvcarndawjkt","xygloneljlznyfjn","nupeykanyuarwpga","rjvudfnpijitnqhq","nkegzfkxgateznel","wyusvppwruawzhxs","iamczuahhfoycboa","eluncxeikhemzicn","wikpugnbioksljbu","kldnyohoedffnnre","twmybwqmnipkubew","jewowvionezvjfbz","undazcjsamkimgrr","nldofhivkzxoueut","custwagewsgprvdz","iezxxnuyttmsuyzk","kmkkgxuahwdwpewm","fetrvijmmftmktxo","hzbidpdbpveucpvr","wdbqipukhswwcuhy","syljfooiywudchxx","hbpkejvwflbalntg","xzxajgtbkrbrpqbr","uppfondzncnotnbz","odnjgpcwmumujqag","pvatcquvslsabluq","ujehngnwukvoigsq","csjoochlyyjmvtiv","axhdocvdnhhxhrqg","xeinrozycxjzkytd","ebjsayvodursegnq","kecdgoxbbewftztn","mmrsxvtqzppnfxgz","cenbbgusewkzcinx","psqtihmvnbzvmrwa","ikxbygadoqczjmpb","lpzmnypsfrslnhee","zgzlyhvhkvbdvxcw","lknzmamwtixyuqtm","tmpeweqlofauknzk","yuwknxxpspucifkh","tfaemnvkgpltorlk","dwzlnhsbizbghqam","kgpwtsjjfwxsxcrt","urcnjsfisklnynji","zxjlqorodwvxuygg","surbiazfawuvvhqj","knhcclucrseeqluy","tzpnsquyonohvqrs","pyzbdmhfsdrtshnd","djpkmpfmdyhdliyr","wwahndcgqdbuivob","fipstoktirqiyntr","wgpheipdbquyartc","xsgcchwtcszacbxe","hdefbvzmajumyxpa","slgvlpschiazbuzp","jcmchebhcpijqvkc","eemfuutkorbqojew","wtjhpoonbwyctudk","kgwlcbwqpxjfmmuo","mbdomqsfzczymmee","byuxdrgjkppfgwfx","vfdimgmjhbzrowig","angwigkxxyjnkmwo","yqrypxaiouawfnss","awrydduqfpkopgag","rgsxiejgsdnebbxn","gveqwjnsngwqizjg","ihekdjpflezdcyby","wjrnvoajsgtwlfgl","hsflwczcliinoltu","twypycpeoejeprze","unulgksvrbexnycz","exbcnfmfmogdzpnq","atcwsawqeomkgnrk","sfpjlswrrwdgtcfo","gqpzctjjkqcvfjzt","kfmujtqzuavgflns","xokkheneobyyzdgo","ckykytaqyiamgbbf","aliwdpiapdcpxttm","rouyulkufjteszvh","otupcnftnygkwfik","ixhfsgqxxovfbvnr","dadauxnoiaowlukf","hqednhpotibofimt","xfrjrnyobhqfdmix","yrmvzptfmqnenwem","khmarzwfozraqaeo","wuourtxwuwbxqzoe","oxsrsnhrxtcsxccy","hemdusceibgjjdur","vjumkrjwdksamupv","zvabgayyeiywpxku","xonszppsymjxfzpy","ctnsswgyzmyhywxb","hfbilqdgljrauoop","ueqabgqxrqygzvdq","jjldfcglalydjjsg","kjqjamlfzzpvlfrq","emowmunobnkavekg","stfpyhalczfpmfmc","nehuiyikngzdioix","ralnnqybtynbyofe","pvdggxmxwafnadxw","fvhmpdbimnsrjfwd","pvbfyujoggdpimsj","rnsthhsqvmjhkkte","ppyzdtzvylmwfqdl","hupzexbiqylativk","tbictgrsohkdzknj","jwfasmrghvjtwdnq","hwdwhfhwtwxbarfq","hgfiexrxpjnsxloz","rrtaquavzbxpvrde","mvtjifbuhdlgkaki","atfuifszwtccuqua","thwvailzfqfumnwo","frapqnllhqtofbuh","wtdokyfgkhuekcuy","sccmthjxkzyvtexu","clytvouohtrvzwko","eqmnnznbgnyrnwnh","sciaettdealjcajf","bnckoopdakxcwrzs","hxorklfsrrdwfbzd","wupnjbiingieoxwc","hypzasprtxxdpqxf","jamvkxhnlxblxptj","hrdvisowlilsnujo","vmmxtkhdlwmsczft","pppvsqzlclqljqoy","qszmikursevhuawr","aeufqnbfrprsvotd","epzoyuznanollaff","hvcyxzyodpwcnnpi","rszqmdgfqbmrkkkk","rfxtgzkmuhavfsjy","axhoxsdtsupokbnr","fexecndueglpoqxh","ptkxtyeiqwmcrevn","felrjpmltqecbchy","megopacbwgpbskrq","qtfpnaojvwebiqeh","ffxugfpyjrsfsdqy","pdfaanypnyyxatje","kyvotbrnewkzmxpu","ujeszxkguiwbcsup","irnxzpsxvahyskcb","izmulzsqpnlcuovt","ythyenkqcdcywoht","jcnupqsllrhaespm","llxorbpbwrffjbww","jxpuvfjjjyealdtj","egnudutlksjsmltq","gejrebitlrnhwoir","tbojuhsbazfeppkq","vnvzfilistuennmb","yywyxnqutsrbktcg","fkgqnsrgxrapyzlf","gqkyoatxjmqrfkjj","eqepbhxdxuzwfkne","lhpjpvjzwbjzdjfp","letybrxeihzilwhm","hhhksdytmdiaoqcw","hcounnncbvticsrz","dksloourgqnfzlne","dptigicqfmmarygc","dzgmmapunjpjdncx","ksucaflbtwebnqaq","nxdhgeramsueamqv","nbuvwbfnddnuwgvv","eawtuucmvdkcyyhy","emitroquhecqqwot","tyonzaaafhaggigt","otfoenhxmkwrjoko","vhfguafpxbxcbvgu","mktwonqzawvugmql","potpedshyzxljjlv","kzgwpoehcxxvnaby","ypiujzehvozugodr","hmsfgvikzsedidyi"});
    Solution* so = new Solution();
    int n = so->longestStrChain(arr);
    cout<<n<<endl;
    return 0;
}