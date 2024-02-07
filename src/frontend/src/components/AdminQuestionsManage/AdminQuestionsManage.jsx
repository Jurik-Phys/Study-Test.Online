import style from './AdminQuestionsManage.module.css'
import { useNavigate } from "react-router-dom"

const AdminQuestionsManage = () => {
  const navigate = useNavigate();

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>
          Questions management
        </div>
        <div className={style.imageBox}>
          <div>
            <img src="edu.png" alt="Education.png" onClick={ ()=>navigate('/admin-questions-view')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/admin-questions-view')}> Education (x)</div>
          </div>
          <div>
            <img src="psyho.png" alt="Psychological.png" onClick={ ()=>navigate('/admin-questions-view')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/admin-questions-view')}>Psychological (y)</div>
          </div>
          <div>
            <img src="funny.png" alt="Funny.png" onClick={ ()=>navigate('/admin-questions-view')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/admin-questions-view')}>Funny (z)</div>
          </div>
        </div>
      </div>
  );
}

export default AdminQuestionsManage;
